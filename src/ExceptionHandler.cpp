#include "../headers/ExceptionHandler.h"

ExceptionHandler ExceptionHandler::instance;

void ExceptionHandler::Open(const std::string &exceptionFile) {
    instance.errorStream.open(exceptionFile);
}

void ExceptionHandler::Close() {
    instance.errorStream.close();
}

void ExceptionHandler::Write(const std::string &message) {
    std::ostream& stream = instance.errorStream;
    stream << message << std::endl;
}


