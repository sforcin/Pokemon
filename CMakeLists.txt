cmake_minimum_required(VERSION 3.13)


project(Pokemon)
set(CMAKE_CXX_STANDARD 14)

include_directories(includeFiles)

add_subdirectory(googletest)

add_executable(Pokemon
    lib/Game.cpp
    lib/Display.cpp
    lib/Player.cpp
    lib/Pokemon.cpp
    lib/main.cpp
)

target_link_libraries(Pokemon gtest gtest_main)

add_executable(runTests lib/test_file.cpp)

target_link_libraries(runTests gtest gtest_main)

target_include_directories(runTests PRIVATE googletest/googletest/include)
