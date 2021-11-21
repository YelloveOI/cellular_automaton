#include <iostream>
#include "Window_view.h"

Window_view::Window_view(unsigned int width, unsigned int height) :
_tile_size(2),
_window_width(width),
_window_height(height),
_gen(0),
_black_tile(sf::Vector2f(_tile_size, _tile_size)),
_open(true),
_screen_buffer(new char*[width]),
_window(
        sf::VideoMode(_tile_size*_window_width, _tile_size*_window_height),
        "Cellular Automaton",
        sf::Style::Close
        )
{
    for(int i = 0; i < width; ++i) {
        _screen_buffer[i] = new char[height];
    }

    for(int i = 0; i < width; ++i) {
        for(int j = 0; j < height; ++j) {
            _screen_buffer[i][j] = 0;
        }
    }

    _black_tile.setFillColor(sf::Color::Black);
    _window.clear(sf::Color::White);
}

void Window_view::println(char* string) {
    if(_gen < _window_height) {
        for(int i = 0; i < _window_width; ++i) {
            _screen_buffer[i][_gen] = string[i];
        }

        ++_gen;
    } else {
        for(int j = 1; j < _window_height; ++j) {
            for(int i = 0; i < _window_width; ++i) {
                _screen_buffer[i][j-1] = _screen_buffer[i][j];
            }
        }

        for(int i = 0; i < _window_width; ++i) {
            _screen_buffer[i][_window_height-1] = string[i];
        }
    }

    display();
}

bool Window_view::open() const {
    return _open;
}

void Window_view::close() {
    _open = false;
    _window.close();
}

Window_view::~Window_view() {
    for(int i = 0; i < _window_width; ++i) {
        delete[] _screen_buffer[i];
    }

    delete[] _screen_buffer;
}

void Window_view::display() {
    _window.clear(sf::Color::White);

    for(int j = 0; j < _window_height; ++j) {
        for(int i = 0; i < _window_width; ++i) {
            if(_screen_buffer[i][j]) {
                _black_tile.setPosition(sf::Vector2f(i*_tile_size, j*_tile_size));
                _window.draw(_black_tile);
            }
        }
    }

    _window.display();
}
