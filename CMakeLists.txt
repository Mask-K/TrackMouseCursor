cmake_minimum_required(VERSION 3.23)
project(Homework1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Homework1 main.cpp src/CursorMover.cpp headers/CursorMover.h headers/IObserver.h src/Console.cpp headers/Console.h src/Logger.cpp headers/Logger.h headers/ExceptionHandler.h src/ExceptionHandler.cpp)
