#include "../headers/Logger.h"


Logger::Logger(std::string filename) : log_file(filename)
{
    if(!log_file.is_open())
        throw std::runtime_error("Can not open file " + filename);
}

void Logger::HandleEvent(CursorMover &cursor) {
    time_t time_now = time(NULL);
    if(PtInRect(&cursor.GetRect(), cursor.GetCursor()) && cursor.state){
        log_file << "[Enter] : " << ctime(&time_now);
        cursor.state = !cursor.state;
    }
    else if(!PtInRect(&cursor.GetRect(), cursor.GetCursor()) && !cursor.state){
        log_file << "[Leave] : " << ctime(&time_now);;
        cursor.state = !cursor.state;
    }
}

Logger::~Logger(){
    log_file.close();
}