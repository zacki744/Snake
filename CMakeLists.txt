# CMakeList.txt : CMake project for Snake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project (Snake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SFML_DIR "C:/Snake/SFML/lib/cmake/SFML")

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5.1 COMPONENTS system window main graphics)
include_directories(${SFML_INCLUDE_DIR})

set(source_files
        "C:/Snake/main.h"
        "C:/Snake/main.cpp"
        "C:/Snake/src/Food.cpp"
        "C:/Snake/src/Snake.cpp"
        "C:/Snake/src/Collision.cpp"
        "C:/Snake/src/State.cpp"
        "C:/Snake/include/Food.hpp"
        "C:/Snake/include/Snake.hpp"
        "C:/Snake/include/Collision.hpp"
        "C:/Snake/include/state.hpp"
)
add_executable(Snake ${source_files})
# include and sorce files
#include_directories(include)
#include_directories(src)
#file(GLOB SOURCES "*.cpp")
#file(GLOB SOURCES "*.hpp")

#add_executable ("Snake" ${SOURCES} "main.h" "include/Food.hpp" "src/Food.cpp" "src/Snake.cpp" "include/Snake.hpp")
target_link_libraries(Snake PRIVATE sfml-graphics sfml-window)
