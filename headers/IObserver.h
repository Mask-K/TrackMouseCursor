#pragma once
#include "CursorMover.h"

class CursorMover;

const int WHITE = 15;
const int GREEN = 10;

class IObserver{
public:
    virtual void HandleEvent(const CursorMover& cr) = 0;
    virtual ~IObserver()=default;
//protected:
//    static bool state;
};

//bool IObserver::state = false;

