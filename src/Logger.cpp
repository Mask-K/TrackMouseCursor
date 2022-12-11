#include "../headers/Logger.h"


Logger::Logger(std::string filename) : log_file(filename)
{
    if(!log_file.is_open())
        throw "bad";
}

void Logger::HandleEvent(const CursorMover &cr) {
    time_t time_now = time(NULL);
    if(cr.GetCursor().x == 0 && cr.GetCursor().y == 0 && cr.state){
        log_file << "[Enter] : " << ctime(&time_now);
        cr.state = !cr.state;
    }
    else if((cr.GetCursor().x != 0 || cr.GetCursor().y != 0) && !cr.state){
        log_file << "[Leave] : " << ctime(&time_now);;
        cr.state = !cr.state;
    }
}

Logger::~Logger(){
    log_file.close();
}