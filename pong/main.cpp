#include <iostream>
#include <SFML/Graphics.hpp>
#include "pos.h"

int get_sec() {
    time_t timer;
    time(&timer);

    struct tm y2k = {0};        //what is this sorcery?

    y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
    y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

    return difftime(timer,mktime(&y2k));;
}

int get_millisec() {
    // Get the current time from the system clock
    auto now = std::chrono::system_clock::now();

    // Convert the current time to time since epoch
    auto duration = now.time_since_epoch();

    // Convert duration to milliseconds
    auto milliseconds
        = std::chrono::duration_cast<std::chrono::milliseconds>(
              duration)
              .count();

    return milliseconds;
}

void pong() {
    //Init all stuff thats needed
    int r = 10;

    sf::RenderWindow win(sf::VideoMode({800, 400}), "Pong");

    sf::RectangleShape p1(sf::Vector2f(20, 100));   //Player 1
    sf::RectangleShape p2(sf::Vector2f(20, 100));   //Player 2
    sf::CircleShape ball(static_cast<float>(r));    //Ball

    p1.setPosition(sf::Vector2f(10, 10));
    p2.setPosition(sf::Vector2f(770, 290));
    ball.setPosition(sf::Vector2f(400, 200));

    //Basic window stuff
    while (win.isOpen()) {
        //TEST
        win.clear(sf::Color::Black);
        win.draw(ball);
        win.draw(p1);
        win.draw(p2);
        if (win.pollEvent()->getIf<sf::Event::Closed>()) win.close();   //close window if close button pressed
        win.display();
    }
}


int main() {
    std::cout << "POOPER" << std::endl;
    pong();
    return 0;
}