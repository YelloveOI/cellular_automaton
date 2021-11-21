#include "App.h"
#include "Cellular_Automaton.h"
#include "Window_view.h"
#include "Console_view.h"

void App::start() {
    //105, 57, 169, 73
    Console_view con_view(_app_width, _app_height);
//    Window_view win_view(_app_width, _app_height);
    Cellular_Automaton ca(_app_width, 73);
    ca.cell(_app_width/2, 'x');
    sf::Clock clock;

    while(con_view.open()) {
        _time = clock.getElapsedTime().asSeconds();

        if(_interval <= _time) {
            clock.restart();

//            win_view.println(ca.map());
            con_view.println(ca.map());
            ca.next();
        }
    }
}

App::App(unsigned int width, unsigned int height) :
_app_width(width),
_app_height(height),
_time(0),
_interval(0.025)
{
}
