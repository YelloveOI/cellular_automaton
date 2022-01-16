#include "Cellular_Automaton.h"
#include "App.h"
#include "thread"
#include "iostream"
#include "windows.h"

const unsigned int WIDTH = 200; //600
const unsigned int HEIGHT = 150; //450
const unsigned int INTERVAL_MS = 25;

int main() {
    std::cout << "Rules range: 0-255, interesting ones: 105, 57, 169, 73, 75, 30" << std::endl;
    std::cout << "<SPACE> for slowdown, <ESC> for quit" << std::endl;
    std::cout << "Enter the rule:";
    unsigned  int rule;
    std::cin >> rule;

    //105, 57, 169, 73, 77, 75, 133
    App app(WIDTH, HEIGHT, rule, INTERVAL_MS);

    std::thread app_thread(&App::start, std::ref(app));

    bool prev_space = false;
    auto space_processor = [&prev_space, &app] () {
        while(true) {
            if(GetAsyncKeyState(VK_SPACE) & 0x8000) {
                if(!prev_space) {
                    app.set_interval(10*INTERVAL_MS);
                    prev_space = true;
                }
            } else {
                if(prev_space) {
                    app.set_interval(INTERVAL_MS);
                    prev_space = false;
                }
            }

            if(GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
                app.stop();
                exit(1);
            }
        }
    };

    std::thread key_processor_thread(space_processor);

    app_thread.join();
    key_processor_thread.join();
    return 0;
}
