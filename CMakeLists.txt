cmake_minimum_required(VERSION 3.23)
project(Cadavre_Exquis C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Cadavre_Exquis
        main.c
        node.c
        node.h
        tree.c
        tree.h flechi.c flechi.h)
