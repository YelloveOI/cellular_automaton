#ifndef CELLULAR_AUTOMATA_APP_H
#define CELLULAR_AUTOMATA_APP_H
#include "views/IView.h"
#include "Cellular_Automaton.h"
#include <queue>
#include <stack>
#include "thread"

class App {
public:
    App() = default;
    ~App();
    App(unsigned int width, unsigned int height, unsigned int game_rule, unsigned int intervalMS);
    void start();
    void set_interval(unsigned int intervalMS);
    void stop();
private:
    bool _power_flag = false;
    const unsigned int _app_width = 0;
    const unsigned int _app_height = 0;
    unsigned int _interval = 0;
    float _time = 0;
    IView* _view = nullptr;
    unsigned int _game_rule = 0;
};


#endif //CELLULAR_AUTOMATA_APP_H
