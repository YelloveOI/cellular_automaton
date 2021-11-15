#include "Cellular_Automaton.h"

Cellular_Automaton::Cellular_Automaton(
        unsigned int width,
        unsigned char rule
        ) :
        _width(width),
        _rule(rule) {
    _map = new bool[width];
    _p_map = new bool[width];

    unsigned char temp = rule;
    unsigned char i = 7;
    while(temp) {
        _conv_rule[i] = temp % 2;
        temp /= 2;
        --i;
    }
}

bool* Cellular_Automaton::map() const {
    return _map;
}

void Cellular_Automaton::next() {
    for(int i = 0; i < _width; ++i) {
        _p_map[i] = _map[i];
    }

    for(int i = 1; i < _width-1; ++i) {
        unsigned char current_case = _p_map[i+1] + _p_map[i]*2 + _p_map[i]*4;
        _map[i] = _conv_rule[current_case];
    }
}
