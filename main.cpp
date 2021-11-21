#include <iostream>
#include <conio.h>
#include "SFML/Graphics.hpp"
#include "Cellular_Automaton.h"
#include "App.h"
#include "Console_view.h"

int main() {

//    App app(180, 45);
    App app(160, 40);
    app.start();

    getch();
    return 0;
}
