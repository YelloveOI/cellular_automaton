cmake_minimum_required(VERSION 3.20)
project(cellular_automata)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        cellular_automata
        views/Window_view.cpp
        views/Window_view.h
        views/IView.cpp
        views/IView.h
        App.cpp
        App.h
        views/Console_view.cpp
        views/Console_view.h
        main.cpp
        Cellular_Automaton.cpp
        Cellular_Automaton.h
        )
