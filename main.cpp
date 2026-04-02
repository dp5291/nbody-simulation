// "Copyright [2024] <Dhruv Patel>"
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Universe.hpp"
#include "CelestialBody.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <T> <delta_t>" << std::endl;
        return 1;
    }
    sf::RenderWindow window(sf::VideoMode(window_height, window_width), "Celestial");

    double t = 0.0;
    double T = std::stod(argv[1]);
    double delta_t = std::stod(argv[2]);
    NB::Universe universe;

    std::cin >> universe;
    sf::Texture texture;
    if (!texture.loadFromFile("starfield.jpg")) {
        std::cout << "File could not open" << std::endl;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::Vector2u textureSize = texture.getSize();
    sf::Vector2u windowSize = window.getSize();
    sprite.setScale(static_cast<float>(windowSize.x) / textureSize.x
    , static_cast<float>(windowSize.y) / textureSize.y);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (t < T) {
            universe.step(delta_t);
            t += delta_t;
        }
        window.clear();
        window.draw(sprite);
        window.draw(universe);
        window.display();
    }

    std::cout << universe;
    return 0;
}
