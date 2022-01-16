#ifndef CELLULAR_AUTOMATA_CELLULAR_AUTOMATON_H
#define CELLULAR_AUTOMATA_CELLULAR_AUTOMATON_H
#include "vector"
#include "SFML/Graphics.hpp"

class Cellular_Automaton {
public:
    Cellular_Automaton() = default;
    Cellular_Automaton(unsigned int width, unsigned char rule);
    ~Cellular_Automaton();
    char* map() const;
    char* pmap() const;
    void next();
    void cell(unsigned int position, bool state);
private:
    const unsigned int _width = 0;
    const unsigned char _rule = 0;
    bool _conv_rule[8] = {};
    char* _map = nullptr;
    char* _p_map = nullptr;
};


#endif //CELLULAR_AUTOMATA_CELLULAR_AUTOMATON_H
