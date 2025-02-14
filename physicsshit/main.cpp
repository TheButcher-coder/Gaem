#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "pos.h"


int get_sec() {
    time_t timer;
    time(&timer);

    struct tm y2k = {0};        //what is this sorcery?

    y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
    y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

    return difftime(timer,mktime(&y2k));;
}
void falling_circ_TEST() {
    sf::RenderWindow win(sf::VideoMode({1000, 1000}), "test falling Ball");
    sf::CircleShape c1(50);
    c1.setFillColor(sf::Color::Cyan);
    int x, y, t;
    y = t = 0;
    x = 500;
    double g = 9.81;


    while (win.isOpen()) {
        win.clear(sf::Color::Black);

        //calculate bal pos
        //y = 1/2*g*t*t/1000;
        c1.setPosition(sf::Vector2f(x, y));

        //t += 1;
        win.draw(c1);
        win.display();
    }
}

void test() {
    // create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");
    Pos oldpos, p0;
    float r = 50;

    //falling_circ_TEST();
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

int main()
{
    test();
    return 0;
}