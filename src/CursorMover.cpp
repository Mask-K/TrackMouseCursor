#include "../headers/CursorMover.h"

CursorMover::CursorMover() : hwnd(GetConsoleWindow())
{}

void CursorMover::NotifyObservers() {
    for(auto &iter : observers)
        iter->HandleEvent(*this);
}

void CursorMover::AddObserver(IObserver &obs) {
    observers.push_back(&obs);
}

POINT CursorMover::GetCursor() const {
    return p;
}

void CursorMover::Track() {
    std::cout << "Track Cursor\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
    std::cout << "Hello world!";
    do{
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        GetCursorPos(&p);
        NotifyObservers();
    }while(GetKeyState(VK_ESCAPE) >= 0);
}