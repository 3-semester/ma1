cmake_minimum_required(VERSION 3.17)
project(Mandatory_assignment_1__the_second C)

set(CMAKE_C_STANDARD 11)

include_directories(String)
include_directories(Shell)


add_executable(Mandatory_assignment_1__the_second
        String/StringUtil.c
        String/StringUtil.h
        Shell/shell.c
        Shell/shell.h
        main.c)
