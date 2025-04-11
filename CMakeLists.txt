cmake_minimum_required(VERSION 3.10)
project(LinkedListProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


include(GoogleTest)
add_subdirectory(external/googletest)

# Include headers
include_directories(include)

# Add library for dynamic linked list
add_library(dll STATIC src/dll.cpp)

# Add library for static linked list
add_library(sll STATIC src/sll.cpp)
target_include_directories(sll PUBLIC include)

# Add the tests directory
add_subdirectory(tests)