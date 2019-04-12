cmake_minimum_required(VERSION 3.13)
project(Project_6)

set(CMAKE_C_STANDARD 14)

add_executable(Project_6 card.h deck.h player.h deck.cpp card.cpp player.cpp go_fish.cpp)
