#include <SFML/Graphics.hpp>
#include <iostream>
#include "pos.h"



int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");
    Pos oldpos;
    float r = 50;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        window.clear(sf::Color::White);
        sf::CircleShape shape(r);

        shape.setFillColor(sf::Color(255, 250, 50));
        sf::CircleShape shape2(r);
        shape2.setFillColor(sf::Color(0, 0, 0));
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>()) {
                //update mousepos
                oldpos = *mouseMoved;
            }
        }
        shape2.setPosition(sf::Vector2f(oldpos.get_x() - r, oldpos.get_y() - r));
        window.draw(shape2);

        window.display();
    }
}