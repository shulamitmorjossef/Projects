cmake_minimum_required(VERSION 3.24)
project(trhw)

set(CMAKE_CXX_STANDARD 20)

add_executable(trhw main.cpp Worker.cpp Worker.h Teacher.cpp Teacher.h Temp.cpp Temp.h Tutor.cpp Tutor.h Deputy.cpp Deputy.h Manager.cpp Manager.h Secretary.cpp Secretary.h School.cpp School.h)
