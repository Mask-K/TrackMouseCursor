#pragma once
#include "IObserver.h"
#include <windows.h>
#include <iostream>
#include <vector>
#include <memory>

class IObserver;

class CursorMover{
public:
    CursorMover();

    void AddObserver(std::shared_ptr<IObserver> obs);
    void Track();

    POINT GetCursor() const;
    RECT& GetRect(){return consoleWindow;}
    mutable bool state = false;
private:
    HWND windowDescriptor;
    HANDLE hConsole;
    POINT point{};
    RECT consoleWindow{};
    CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo{};
    std::vector<std::shared_ptr<IObserver>> observers;
    void NotifyObservers();
};
