cmake_minimum_required(VERSION 3.23)
project(TP3_Djikstra C)

set(CMAKE_C_STANDARD 99)

add_executable(TP3_Djikstra main.c graphe.h djikstra/djikstra.c djikstra/djikstra.h)
