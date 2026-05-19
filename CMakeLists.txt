cmake_minimum_required(VERSION 4.1)
project(Proiect_SD)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proiect_SD
        main.cpp
        sorts.h
        merge/merge_sort.cpp
        test_case_generator.cpp
        heap/heap_sort.cpp
        gnome/gnome_sort.cpp)

target_include_directories(Proiect_SD PRIVATE .)