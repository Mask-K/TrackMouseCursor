#pragma once
#include "IObserver.h"
#include <fstream>

class Logger : public IObserver{
public:
    Logger(std::string filename);
    void HandleEvent(const CursorMover& cr);
    ~Logger();
private:
    std::ofstream log_file;
};

