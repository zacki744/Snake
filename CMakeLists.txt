# CMakeList.txt : CMake project for Snake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project (Snake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML/lib/cmake/SFML")

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5.1 COMPONENTS system window main graphics)
include_directories(${SFML_INCLUDE_DIR})

set(source_files   
        main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/Snake.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/Food.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/Collision.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/State.cpp
        ${CMAKE_CURRENT_LIST_DIR}/include/Snake.hpp
        ${CMAKE_CURRENT_LIST_DIR}/include/Food.hpp
        ${CMAKE_CURRENT_LIST_DIR}/include/Collision.hpp
        ${CMAKE_CURRENT_LIST_DIR}/include/State.hpp
)
include_directories()

add_executable(Snake ${source_files})
target_link_libraries(Snake PRIVATE sfml-graphics sfml-window)
#heders
target_include_directories(Snake
    PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include"                          
)
