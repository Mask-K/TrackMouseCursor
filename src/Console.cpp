#include "../headers/Console.h"

void Console::HandleEvent(CursorMover &cursor)  {
    if(PtInRect(&cursor.GetRect(), cursor.GetCursor()) && cursor.state){
        system("cls");
        if(!SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE))
            throw std::runtime_error("Can not set characters' attributes to the console");
        std::cout << "Hello, world";
    }
    else if(!PtInRect(&cursor.GetRect(), cursor.GetCursor()) && !cursor.state){
        system("cls");
        if(!SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN))
            throw std::runtime_error("Can not set characters' attributes to the console");
        std::cout << "Hello, world";
    }
}