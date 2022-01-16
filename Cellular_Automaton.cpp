#include <iostream>
#include "Cellular_Automaton.h"
#include "vector"

Cellular_Automaton::Cellular_Automaton(unsigned int width, unsigned char rule) :
_width(width),
_rule(rule),
_p_map(new char[width]),
_map(new char[width])
{
    for(int i = 0; i < width; ++i) {
        _map[i] = 0;
        _p_map[i] = 0;
    }

    unsigned char temp = rule;
    unsigned char i = 0;

    while(temp) {
        _conv_rule[i] = temp % 2;
        temp /= 2;
        ++i;
    }
}

char* Cellular_Automaton::map() const {
    return _map;
}

void Cellular_Automaton::next() {
    for(int i = 0; i < _width; ++i) {
        _p_map[i] = _map[i];
    }

    for(int i = 0; i < _width; ++i) {
        _map[i] = 0;
    }


    for(int i = 1; i < _width-1; ++i) {
        unsigned int current_case = 0;
        if(_p_map[i+1]) current_case += 1;
        if(_p_map[i]) current_case += 2;
        if(_p_map[i-1]) current_case += 4;
        if(_conv_rule[current_case]) {
            _map[i] = 1;
        }
    }
}

void Cellular_Automaton::cell(unsigned int position, bool state) {
    _map[position-1] = state;
    _p_map[position-1] = state;
}

char* Cellular_Automaton::pmap() const {
    return _p_map;
}

Cellular_Automaton::~Cellular_Automaton() {
    delete[] _map;
    delete[] _p_map;
}

