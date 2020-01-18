cmake_minimum_required(VERSION 3.15)
project(Calculator_In_CLion)

set(CMAKE_CXX_STANDARD 14)

file(COPY solidBlocks.xml DESTINATION \\)

add_executable(Calculator_In_CLion main.cpp
        allHeaders.h
        fluidItems.cpp
        fluidItems.h
        Initializer.cpp
        Initializer.h
        solidItems.cpp
        solidItems.h
        tinyxml2.h
        tinyxml2.cpp
        solidBlocks.xml
        solidCraftMark.cpp
        solidCraftMark.h
        fluidCraftMark.cpp
        fluidCraftMark.h CraftSystem.cpp CraftSystem.h)

