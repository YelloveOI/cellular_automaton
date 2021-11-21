cmake_minimum_required(VERSION 3.20)
project(cellular_automata)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        cellular_automata
        Window_view.cpp
        Window_view.h
        Abstract_view.cpp
        Abstract_view.h
        Controller.cpp
        Controller.h
        App.cpp
        App.h
        Console_view.cpp
        Console_view.h
        main.cpp
        Cellular_Automaton.cpp
        Cellular_Automaton.h
        )

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR c:/SFML/lib/cmake/SFML)
find_package(SFML 2.5.1 COMPONENTS system window graphics)

include_directories(c:/SFML/include)
target_link_libraries(cellular_automata sfml-system sfml-window sfml-graphics)