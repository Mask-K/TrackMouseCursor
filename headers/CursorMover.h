#pragma once
#include "IObserver.h"
#include <windows.h>
#include <iostream>
#include <vector>

class IObserver;

class CursorMover{
public:
    CursorMover();

    void AddObserver(IObserver& obs);
    void Track();

    POINT GetCursor() const;
    mutable bool state = false;
private:
    HWND hwnd;
    POINT p{};
    CONSOLE_SCREEN_BUFFER_INFO csbi{};
    std::vector<IObserver*> observers;
    void NotifyObservers();
};
