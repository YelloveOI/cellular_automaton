#include <iostream>
#include "Cellular_Automaton.h"

Cellular_Automaton::Cellular_Automaton(
        unsigned int width,
        unsigned char rule
        ) :
        _width(width),
        _rule(rule) {
    for(int i = 0; i < width; ++i) {
        _map.push_back(false);
        _p_map.push_back(false);
    }
    unsigned char temp = rule;
    unsigned char i = 0;
    while(temp) {
        _conv_rule[i] = temp % 2;
        temp /= 2;
        ++i;
    }
}

std::vector<bool> Cellular_Automaton::map() const {
    return std::vector<bool>(_map);
}

void Cellular_Automaton::next() {
    for(int i = 0; i < _width; ++i) {
        _p_map.at(i) = map().at(i);
    }

    for(int i = 1; i < _width-1; ++i) {
        unsigned int current_case = 0; // = _p_map.at(i+1) + _p_map.at(i)*2 + _p_map.at(i-1)*4;
        if(_p_map.at(i+1)) current_case += 1;
        if (_p_map.at(i)) current_case += 2;
        if(_p_map.at(i-1)) current_case += 4;
//        std::cout << current_case;
        _map.at(i) = _conv_rule[current_case];
        current_case = 0;
    }
//    std::cout << std::endl;
}

void Cellular_Automaton::cell(unsigned int position, bool state) {
    _map.at(position-1) = state;
}

