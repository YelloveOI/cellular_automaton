#include <iostream>
#include "Cellular_Automaton.h"
#include "vector"

Cellular_Automaton::Cellular_Automaton(unsigned int width, unsigned char rule) :
_width(width),
_rule(rule),
_p_map(std::vector<bool>(width)),
_map(std::vector<bool>(width))
{
    unsigned char temp = rule;
    unsigned char i = 0;

    while(temp) {
        _conv_rule[i] = temp % 2;
        temp /= 2;
        ++i;
    }

    _p_map.at(width/2) = true;
    _map.at(width/2) = true;
}

void Cellular_Automaton::map(std::vector<bool> &to_fill) const {
    to_fill.clear();
    for(auto e : _map) {
        to_fill.push_back(e);
    }
}

void Cellular_Automaton::next() {
    _p_map = _map;

    for(int i = 1; i < _width-1; ++i) {
        unsigned int current_case = 0;

        if(_p_map.at(i+1)) current_case += 1;
        if(_p_map.at(i)) current_case += 2;
        if(_p_map.at(i-1)) current_case += 4;

        if(_conv_rule[current_case]) {
            _map.at(i) = true;
        } else {
            _map.at(i) = false;
        }
    }
}

void Cellular_Automaton::cell(unsigned int position, bool state) {
    _map.at(position-1) = state;
    _p_map.at(position-1) = state;
}

Cellular_Automaton::~Cellular_Automaton() = default;

