#include <iostream>
#include "Console_view.h"

Console_view::~Console_view() {
    delete _screen_buffer;
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
    _COORD console_buffer_size = {static_cast<SHORT>(width), static_cast<SHORT>(height)};
    _SMALL_RECT console_rect = {0, 0, static_cast<SHORT>(width - 1), static_cast<SHORT>(height - 1)};
    HWND console = GetConsoleWindow();

    SetConsoleScreenBufferSize(handle, console_buffer_size);
    SetConsoleWindowInfo(handle, TRUE, &console_rect);

//    CONSOLE_FONT_INFOEX cfi;
//    COORD font_size = GetConsoleFontSize(handle, 0);

//    cfi.cbSize = sizeof(cfi);
//    cfi.nFont = 0;
//    cfi.dwFontSize.X = font_size.X/1.5;
//    cfi.dwFontSize.Y = font_size.Y/1.5;
//    cfi.FontFamily = FF_DONTCARE;
//    cfi.FontWeight = FW_NORMAL;
//    std::wcscpy(cfi.FaceName, L"ca_font");
//    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

//    CONSOLE_FONT_INFOEX font = {};
//    const short FONT_WIDTH = font.dwFontSize.X/2;
//    const short FONT_HEIGHT = font.dwFontSize.Y/2;
//
//    GetCurrentConsoleFontEx(handle, false, &font);
//    font.dwFontSize = { FONT_WIDTH, FONT_HEIGHT};
//    font.cbSize = sizeof(font)/2;
//    SetCurrentConsoleFontEx(handle, false, &font);

}

void Console_view::print(char** screen) {

}

void Console_view::println(char* string) {
    if(_gen < _console_height) {
        for(int i = 0; i < _console_width; ++i) {
            _screen_buffer[_gen*_console_width+i] = string[i];
        }

        ++_gen;
    } else {
        for(int j = 1; j < _console_height; ++j) {
            for(int i = 0; i < _console_width; ++i) {
                _screen_buffer[(j-1)*_console_width+i] = _screen_buffer[j*_console_width+i];
            }
        }

        for(int i = 0; i < _console_width; ++i) {
            _screen_buffer[(_console_height-1)*_console_width+i] = string[i];
        }
    }

    display();
}

boolean Console_view::open() const {
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

