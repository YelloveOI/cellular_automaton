cmake_minimum_required(VERSION 3.20)
project(cellular_automata)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        cellular_automata
        main.cpp
        Cellular_Automaton.cpp
        Cellular_Automaton.h
        )

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR c:/SFML/lib/cmake/SFML)
find_package(SFML 2.5.1 COMPONENTS system window graphics)

include_directories(c:/SFML/include)
target_link_libraries(cellular_automata sfml-system sfml-window sfml-graphics)