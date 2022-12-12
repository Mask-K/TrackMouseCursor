#include "../headers/CursorMover.h"


CursorMover::CursorMover() : windowDescriptor(GetConsoleWindow()), hConsole(GetStdHandle(STD_OUTPUT_HANDLE))
{
    if(!windowDescriptor)
        throw std::runtime_error("Associated console was not found");
    if(hConsole == INVALID_HANDLE_VALUE || !hConsole)
        throw std::runtime_error("A handle can not be retrieved");
}

void CursorMover::NotifyObservers() {
    for(auto &iter : observers)
        iter->HandleEvent(*this);
}

POINT CursorMover::GetCursor() const {
    return point;
}

void CursorMover::Track() {
    if(!SetCursorPos(0, 0)) // outside the console window
        throw std::runtime_error("Can not provide (0; 0) cursor coordinates");
    if(!SetConsoleTextAttribute(hConsole, GREEN))
        throw std::runtime_error("Can not set characters' attributes to the console");
    std::cout << "Hello world!";
    do{
        try {
            if (!GetConsoleScreenBufferInfo(hConsole, &consoleScreenBufferInfo))
                throw std::runtime_error("Can not retrieve information about the console screen buffer");

            if (!GetCursorPos(&point))
                throw std::runtime_error("Can not retrieve the position of the mouse cursor, in screen coordinates");

            if (!ScreenToClient(windowDescriptor, &point))
                throw std::runtime_error("Can not convert global cursor coordinate to the console-area coordinate");

            if (!GetClientRect(windowDescriptor, &consoleWindow))
                throw std::runtime_error("Can not retrieve the coordinates of the console window");

            NotifyObservers();
        }
        catch (const std::exception& ex){
            std::string error = "An exception has occured: " + std::to_string(*ex.what());
            ExceptionHandler::Write(error);
        }
    }while(GetKeyState(VK_ESCAPE) >= 0);
}

void CursorMover::AddObserver(std::shared_ptr<IObserver> obs) {
    observers.push_back(obs);
}
