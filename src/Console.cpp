#include "../headers/Console.h"

void Console::HandleEvent(const CursorMover &cr)  {
    if(cr.GetCursor().x == 0 && cr.GetCursor().y == 0 && cr.state){
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        std::cout << "Hello, world";
    }
    else if((cr.GetCursor().x != 0 || cr.GetCursor().y != 0) && !cr.state){
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
        std::cout << "Hello, world";
    }
}