#ifndef CELLULAR_AUTOMATA_CONSOLE_VIEW_H
#define CELLULAR_AUTOMATA_CONSOLE_VIEW_H
#include "windows.h"
#include "IView.h"

class Console_view : public IView {
public:
    Console_view(unsigned short width, unsigned short height);
    Console_view() = default;
    ~Console_view() override;

    void println(char* line) override;
    void print(std::vector<bool> screen) override;
    bool open() const override;
    void clear();
    void close();

private:
    void display();
    bool _open = true;
    unsigned short _console_width = 0;
    unsigned short _console_height = 0;
    char* _screen_buffer = nullptr;
    unsigned int _gen = 0;
};


#endif //CELLULAR_AUTOMATA_CONSOLE_VIEW_H
