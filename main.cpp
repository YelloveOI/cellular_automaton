#include <conio.h>
#include "Cellular_Automaton.h"
#include "App.h"

int main() {

    //105, 57, 169, 73, 77, 75, 133
    App app(320, 160, 105, 25);
    app.start();

    getch();
    return 0;
}
