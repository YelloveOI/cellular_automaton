#include <iostream>
#include "Console_view.h"

const char FILLED = (char)219;
const char BLANK = (char)176;

Console_view::~Console_view() {
    delete[] _screen_buffer;
}

Console_view::Console_view(unsigned short width, unsigned short height) :
        _console_width(width),
        _console_height(height),
        _screen_buffer(nullptr),
        _open(true),
        _gen(0)
{
    const unsigned int SQUARE = width*height;
    _screen_buffer = new char[SQUARE];
    for(int i = 0; i < SQUARE; i++) {
        _screen_buffer[i] = 0;
    }

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    _SMALL_RECT console_rect = { 0, 0, 1, 1 };

    SetConsoleWindowInfo(handle, TRUE, &console_rect);

    // set screen buffer size
    COORD coord = { (short)_console_width, (short)_console_height };
    SetConsoleScreenBufferSize(handle, coord);

    // attaches screen buffer to console
    SetConsoleActiveScreenBuffer(handle);

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 4;
    cfi.dwFontSize.Y = 4;

    wcscpy_s(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(handle, false, &cfi);

    // set console window size
    console_rect = { 0, 0, static_cast<SHORT>((short)_console_width - 1), static_cast<SHORT>((short)_console_height - 1) };
    SetConsoleWindowInfo(handle, TRUE, &console_rect);

}

void Console_view::print(char** screen) {

}

void Console_view::println(char* line) {
    if(_gen < _console_height) {
        for(int i = 0; i < _console_width; ++i) {
            if(line[i]) {
                _screen_buffer[_gen*_console_width+i] = FILLED;
            } else {
                _screen_buffer[_gen*_console_width+i] = BLANK;
            }
        }

        ++_gen;
    } else {
        for(int j = 1; j < _console_height; ++j) {
            for(int i = 0; i < _console_width; ++i) {
                _screen_buffer[(j-1)*_console_width+i] = _screen_buffer[j*_console_width+i];
            }
        }

        for(int i = 0; i < _console_width; ++i) {
//            _screen_buffer[(_console_height-1)*_console_width+i] = line[i];
            if(line[i]) {
                _screen_buffer[(_console_height-1)*_console_width+i] = FILLED;
            } else {
                _screen_buffer[(_console_height-1)*_console_width+i] = BLANK;
            }
        }
    }

    display();
}

bool Console_view::open() const {
    return _open;
}

void Console_view::close() {
    _open = false;
}

void Console_view::display() {
    _screen_buffer[_console_width * _console_height - 1] = '\0';
    DWORD dw = 0;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    WriteConsoleOutputCharacter(handle, _screen_buffer, _console_height * _console_width, {0, 0 }, &dw);
}
