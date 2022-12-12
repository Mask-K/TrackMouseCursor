#pragma once
#include "CursorMover.h"
#include "ExceptionHandler.h"

class CursorMover;

const int WHITE = 15;
const int GREEN = 10;

class IObserver{
public:
    virtual void HandleEvent(CursorMover& cursor) = 0;
    virtual ~IObserver()=default;
};


