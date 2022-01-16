cmake_minimum_required(VERSION 3.16.3)
project(cellular_automata)

set(CMAKE_CXX_STANDARD 14)
set(COMPILER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${COMPILER_FLAGS}")


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

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(cellular_automata Threads::Threads)