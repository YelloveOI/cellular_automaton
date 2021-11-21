#ifndef CELLULAR_AUTOMATA_CONSOLE_VIEW_H
#define CELLULAR_AUTOMATA_CONSOLE_VIEW_H
#include "windows.h"


class Console_view {
public:
    Console_view(unsigned short width, unsigned short height);
    Console_view() = default;
    ~Console_view();

    void print(char** screen);
    void println(char* string);
    boolean open() const;
    void close();

private:
    void display();
    boolean _open = true;
    unsigned short _console_width = 0;
    unsigned short _console_height = 0;
    char* _screen_buffer = nullptr;
    unsigned int _gen = 0;
};


#endif //CELLULAR_AUTOMATA_CONSOLE_VIEW_H
