#include <ctime>
#include "App.h"
#include "views/Window_view.h"
#include "views/Console_view.h"

void App::start() {
    Console_view con_view(_app_width, _app_height);
    clock_t tick = clock();
    _view = &con_view;
    _power_flag = true;

    _ca.cell(_app_width/2, 'X');

    while(con_view.open() && _power_flag) {
        _time = (float)(clock() - tick);

        if(_interval <= _time) {
            tick = clock();
            _view->println(_ca.map());
            _ca.next();
        }
    }
}

App::App(unsigned int width, unsigned int height, unsigned int game_rule, unsigned int intervalMS) :
_app_width(width),
_app_height(height),
_time(0),
_interval(intervalMS),
_view(nullptr),
_ca(Cellular_Automaton(_app_width, game_rule))
{
}

App::~App() {
    delete _view;
}

void App::set_interval(unsigned int intervalMS) {
    _interval = ((float)intervalMS);
}

void App::stop() {
    _power_flag = false;
    _view->clear();
}
