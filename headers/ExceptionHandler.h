#pragma once
#include <fstream>

class ExceptionHandler{
public:
    static void Open( const std::string& exceptionFile);
    static void Close();
    static void Write(const std::string& message);
private:
    ExceptionHandler() = default;
    std::ofstream errorStream;
    static ExceptionHandler instance;
};


