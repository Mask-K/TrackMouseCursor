#include "headers/Logger.h"
#include "headers/Console.h"
int main(){
    Console console;
    Logger log("info.log");
    CursorMover cursor;
    cursor.AddObserver(console);
    cursor.AddObserver(log);
    cursor.Track();

//    HWND hwnd = GetConsoleWindow();
//    POINT p;
//    CONSOLE_SCREEN_BUFFER_INFO csbi;
//    //SetCursorPos(500, 500);
//    bool flag = true;
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    SetConsoleTextAttribute(hConsole, 10);
//    std::cout << "Hello world!";
//    do{
//        GetConsoleScreenBufferInfo(hConsole, &csbi);
//        GetCursorPos(&p);
//
////        ScreenToClient(hwnd, &p);
////        RECT cr;
////        GetClientRect(hwnd, &cr);
//        if(p.x == 0 && p.y == 0 && flag){
//            system("cls");
//            SetConsoleTextAttribute(hConsole, 15);
//            std::cout << "Hello, world";
//            flag = false;
//        }
//        else if((p.x !=0 || p.y != 0) && !flag){
//            system("cls");
//            SetConsoleTextAttribute(hConsole, 10);
//            std::cout << "Hello, world";
//            flag = true;
//        }
//
//    }while(GetKeyState(VK_ESCAPE) >= 0);
    return 0;
}