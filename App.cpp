#include <conio.h>
#include "App.h"
#include "views/Window_view.h"
#include "views/Console_view.h"

void App::start() {
    Console_view con_view(_app_width, _app_height);
    sf::Clock clock;
    _view = &con_view;

    _ca.cell(_app_width/2, 'X');

    while(con_view.open()) {
        _time = clock.getElapsedTime().asSeconds();

        if(_interval <= _time) {
            clock.restart();
            _view->println(_ca.map());
            _ca.next();
        }
    }
    _view = nullptr;
}

App::App(unsigned int width, unsigned int height, unsigned int game_rule, unsigned int intervalMS) :
_app_width(width),
_app_height(height),
_time(0),
_interval(intervalMS/1000),
_view(nullptr),
_ca(Cellular_Automaton(_app_width, game_rule))
{
}

App::~App() {
    delete _view;
}

void App::set_interval(unsigned int intervalMS) {
    _interval = ((float)intervalMS)/1000;
}
