//#ifndef CELLULAR_AUTOMATA_WINDOW_VIEW_H
//#define CELLULAR_AUTOMATA_WINDOW_VIEW_H
//
//#include "SFML/Graphics.hpp"
//#include "IView.h"
//
//class Window_view : public IView {
//public:
//    Window_view() = default;
//    ~Window_view() override;
//    Window_view(unsigned int width, unsigned int height);
//
//    void println(char* string) override;
//    void print(char** screen) override;
//    bool open() const override;
//    void close();
//private:
//    void display();
//    bool _open = true;
//    const unsigned short _tile_size = 0;
//    const unsigned int _window_width = 0;
//    const unsigned int _window_height = 0;
//    char** _screen_buffer = nullptr;
//    unsigned int _gen = 0;
//    sf::RectangleShape _black_tile;
//    sf::RenderWindow _window;
//};
//
//
//#endif //CELLULAR_AUTOMATA_WINDOW_VIEW_H