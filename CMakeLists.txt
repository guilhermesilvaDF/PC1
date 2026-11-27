cmake_minimum_required(VERSION 4.4)
project(ProjetoPC1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ProjetoPC1
        arquivo.c
        arquivo.h
        livro.c
        livro.h
        main.c
        utils.c
        utils.h
        vetor.c
        vetor.h)
