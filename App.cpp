#include <ctime>
#include <iostream>
#include "App.h"
#include "views/Window_view.h"
#include "views/Console_view.h"
#include "mutex"

App::App(unsigned int width, unsigned int height, unsigned int game_rule, unsigned int intervalMS) :
_app_width(width),
_app_height(height),
_time(0),
_interval(intervalMS),
_view(new Console_view(width, height)),
_power_flag(true),
_game_rule(game_rule)
{
}

void App::start() {
    std::queue<std::vector<bool>> screens;
    Cellular_Automaton ca(_app_width, _game_rule);
    bool calculate_flag = true;
    clock_t tick = clock();



    auto calculate_screen = [&screens, &calculate_flag, &ca] (unsigned int height, unsigned int width) {
        unsigned int gen = 0;

        std::vector<bool> line;
        std::vector<bool> screen(height*width);

        while(calculate_flag) {
            ca.map(line);
            ca.next();
            std::this_thread::sleep_for(std::chrono::milliseconds(15));

            if(gen < height) {
                for(int i = 0; i < width; ++i) {
                    if(line[i]) {
                        screen.at(gen*width+i) = true;
                    } else {
                        screen.at(gen*width+i) = false;
                    }
                }
                ++gen;
            } else {
                for(int j = 1; j < height; ++j) {
                    for(int i = 0; i < width; ++i) {
                        screen.at((j-1)*width+i) = screen.at(j*width+i);
                    }
                }

                for(int i = 0; i < width; ++i) {
                    if(line[i]) {
                        screen.at((height-1)*width+i) = true;
                    } else {
                        screen.at((height-1)*width+i) = false;
                    }
                }
            }

            if(screens.size() > 100) {
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
            }

            screens.push(screen);
        }
    };
    std::thread calculate_screen_thread(calculate_screen, _app_height, _app_width);

    while(_view->open() && _power_flag) {
        _time = (float)(clock() - tick);

        if(_interval <= _time) {
            tick = clock();
            if(!screens.empty()) {
                _view->print(screens.front());
                screens.pop();
            }
        }
    }

    calculate_flag = false;
    calculate_screen_thread.join();
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
