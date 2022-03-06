# CMakeList.txt : CMake project for Snake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Snake")

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "C:/Snake/SFML/lib/cmake/SFML")

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5.1 COMPONENTS system window main graphics)
include_directories(${SFML_INCLUDE_DIR})
# Add source to this project's executable.

include_directories(include)
include_directories(src)
file(GLOB SOURCES "*.cpp")

add_executable ("Snake" ${SOURCES} "Snake.h")
target_link_libraries("Snake" PRIVATE sfml-graphics sfml-window)
# TODO: Add tests and install targets if needed.
