cmake_minimum_required(VERSION 3.26)
project(CProjects C)

set(CMAKE_C_STANDARD 11)

add_executable(CProjects
        projekt2/projekt2.c
        projekt3/projekt3.c
        projekt3/projekt3.c
        projekt4/projekt4-LIFO-tablica.c
        projekt4/projekt4-LIFO-lista.c
        projekt4/projekt4-FIFO-lista.c
        projekt4/projekt4-FIFO-tablica.c)
