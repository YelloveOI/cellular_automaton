#include <iostream>
#include "SFML/Graphics.hpp"
#include "Cellular_Automaton.h"

int main() {
    //105,
    const unsigned short tile_size = 2;
    const float interval = 0.01;
    const unsigned int window_width = 400;
    const unsigned int window_height = 500;
    float time = 0;
    Cellular_Automaton ca(
            window_width, 54
            );
    sf::Clock clock;
    sf::RectangleShape black_tile(sf::Vector2f(tile_size, tile_size));
    black_tile.setFillColor(sf::Color::Black);
    sf::RenderWindow window(
            sf::VideoMode(tile_size*window_width, tile_size*window_height),
            "Cellular Automaton",
            sf::Style::Close
            );
    unsigned int gen = 0;

    window.clear(sf::Color::White);
//    window.setFramerateLimit(60);
    ca.cell(window_width/2, true);

    while(window.isOpen()) {
        sf::Event ev;
        time = clock.getElapsedTime().asSeconds();

        while(window.pollEvent(ev)) {
            if(ev.type == ev.Closed) {
                window.close();
            }
        }

        if(interval <= time) {
            clock.restart();

            for(int i = 0; i < window_width; ++i) {
                if(ca.map().at(i)) {
                    black_tile.setPosition(sf::Vector2f(i*tile_size, gen*tile_size));
                    window.draw(black_tile);
                    window.display();
                }
            }

            ++gen;
            ca.next();
        }
    }
}
