//
// Created by Mi on 20.11.2021.
//

#ifndef CELLULAR_AUTOMATA_APP_H
#define CELLULAR_AUTOMATA_APP_H


class App {
public:
    App() = default;
    ~App() = default;
    App(unsigned int width, unsigned int height);
    void start();
private:
    const unsigned int _app_width = 0;
    const unsigned int _app_height = 0;
    const float _interval = 0.025;
    float _time = 0;
};


#endif //CELLULAR_AUTOMATA_APP_H
