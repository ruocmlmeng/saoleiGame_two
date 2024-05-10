cmake_minimum_required(VERSION 3.28)
project(saoleiGame_two C)

set(CMAKE_C_STANDARD 11)

add_executable(saoleiGame_two test.c
        game.c
        game.h)
