#include <sstream>
#include "Cellular_Automaton.h"
#include "App.h"
#include "thread"
#include "iostream"
#include "windows.h"

const unsigned int WIDTH = 400; //600
const unsigned int HEIGHT = 300; //450
const unsigned int INTERVAL_MS = 5;

int main(int argc, char* argv[]) {
//    std::cout << "Rules range: 0-255, interesting ones: 105, 57, 169, 73, 75, 30" << std::endl;
//    std::cout << "<SPACE> for slowdown, <ESC> for quit" << std::endl;
//    std::cout << "Enter the rule:";
//    unsigned  int rule;
//    std::cin >> rule;

    char help[6] = {'-', '-', 'h', 'e', 'l', 'p'};
    int rule;

    if(argc > 2 || argc == 0) {
        exit(EXIT_FAILURE);
    } else {
        if(
                argv[1][0] == help[0] &&
                argv[1][1] == help[1] &&
                argv[1][2] == help[2] &&
                argv[1][3] == help[3] &&
                argv[1][4] == help[4] &&
                argv[1][5] == help[5]
                ) {
            std::cout << "Rules range: 0-255, interesting ones: 105, 57, 169, 73, 75, 30" << std::endl;
            std::cout << "<SPACE> for slowdown, <ESC> for quit" << std::endl;
            std::cout << "Enter the rule:";
            exit(1);
        }

        std::stringstream stream(argv[1]);
        stream >> rule;
        if(!rule) {
            exit(EXIT_FAILURE);
        }
    }

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
