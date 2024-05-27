cmake_minimum_required(VERSION 3.5)

project(06.homework)

add_executable(06.homework main.cpp
        DynamicArray.h LinkedList.h
        SinglyLinkedList.h)
set_target_properties(06.homework PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )