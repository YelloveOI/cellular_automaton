#ifndef CELLULAR_AUTOMATA_CELLULAR_AUTOMATON_H
#define CELLULAR_AUTOMATA_CELLULAR_AUTOMATON_H


class Cellular_Automaton {
public:
    Cellular_Automaton() = default;
    Cellular_Automaton(unsigned int width, unsigned char rule);
    ~Cellular_Automaton() = default;
    bool* map() const;
    void next();
private:
    const unsigned int _width = 0;
    const unsigned char _rule = 0;
    bool _conv_rule[8] = {};
    bool* _map = nullptr;
    bool* _p_map = nullptr;
};


#endif //CELLULAR_AUTOMATA_CELLULAR_AUTOMATON_H
