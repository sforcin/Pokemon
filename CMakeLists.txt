cmake_minimum_required(VERSION 3.13)

project(Pokemon)
set(CMAKE_CXX_STANDARD 14)

include_directories(includeFiles)

add_subdirectory(googletest)


add_executable(Pokemon
    main.cpp
    lib/Game.cpp
    lib/Display.cpp
    lib/Player.cpp
    lib/Item.cpp
    lib/Pokemon.cpp
)

target_link_libraries(Pokemon pthread)


add_executable(runTests
    tests/GameTest.cpp
    tests/PlayerTest.cpp
    lib/Game.cpp
    lib/Display.cpp
    lib/Player.cpp
    lib/Item.cpp
    lib/Pokemon.cpp
)

target_link_libraries(runTests gtest gtest_main pthread)
target_include_directories(runTests PRIVATE googletest/googletest/include)


