#pragma once
#include "IObserver.h"

class Console : public IObserver{
public:
    void HandleEvent(const CursorMover& cr) override;
};