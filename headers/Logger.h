#pragma once
#include "IObserver.h"
#include <fstream>

class Logger : public IObserver{
public:
    Logger(std::string filename);
    void HandleEvent(CursorMover& cursor) override;
    ~Logger();
private:
    std::ofstream log_file;
};

