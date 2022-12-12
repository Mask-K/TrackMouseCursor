#include "headers/Logger.h"
#include "headers/Console.h"

int main(){
    ExceptionHandler::Open("exceptions.txt");
    try {
        auto console = std::make_shared<Console>();
        auto log = std::make_shared<Logger>("info.log");
        CursorMover cursor;

        cursor.AddObserver(console);
        cursor.AddObserver(log);

        cursor.Track();
    }
    catch(const std::exception& ex){
        std::string error = "An exception has occured: " + std::to_string(*ex.what());
        ExceptionHandler::Write(error);
    }

    ExceptionHandler::Close();

    return 0;
}