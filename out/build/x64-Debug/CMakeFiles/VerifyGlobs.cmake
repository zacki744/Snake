# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.20
cmake_policy(SET CMP0009 NEW)

# source_files at CMakeLists.txt:17 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "C:/Snake/*.cpp")
set(OLD_GLOB
  "C:/Snake/main.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/Snake/out/build/x64-Debug/CMakeFiles/cmake.verify_globs")
endif()

# source_files at CMakeLists.txt:17 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "C:/Snake/*.h")
set(OLD_GLOB
  "C:/Snake/main.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/Snake/out/build/x64-Debug/CMakeFiles/cmake.verify_globs")
endif()

# source_files at CMakeLists.txt:17 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "C:/Snake/include/*.h")
set(OLD_GLOB
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/Snake/out/build/x64-Debug/CMakeFiles/cmake.verify_globs")
endif()

# source_files at CMakeLists.txt:17 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "C:/Snake/src/*.cpp")
set(OLD_GLOB
  "C:/Snake/src/Collision.cpp"
  "C:/Snake/src/Food.cpp"
  "C:/Snake/src/Snake.cpp"
  "C:/Snake/src/State.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/Snake/out/build/x64-Debug/CMakeFiles/cmake.verify_globs")
endif()