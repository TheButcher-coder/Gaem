#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <chrono>
#include <stdlib.h>

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
    int winx=800, winy=400;
    int px=20, py=100;

    //init random
    srand(time(NULL));
    Pos v_ball((rand()%100)/100, (rand()%100)/100);   //initial speed of ball
    sf::RenderWindow win(sf::VideoMode({static_cast<unsigned>(winx), static_cast<unsigned>(winy)}), "Pong");

    sf::RectangleShape p1(sf::Vector2f(px, py));   //Player 1
    sf::RectangleShape p2(sf::Vector2f(px, py));   //Player 2
    sf::CircleShape ball(static_cast<float>(r));    //Ball

    //start positions
    p1.setPosition(sf::Vector2f(10, 10));
    p2.setPosition(sf::Vector2f(770, 290));
    ball.setPosition(sf::Vector2f(400, 200));

    //Basic window stuff
    while (win.isOpen()) {
        //TEST
        win.clear(sf::Color::Black);

        //Keylistener shit

        auto pos1=p1.getPosition(), pos2=p2.getPosition();

        if (pos1.y - 1> 0) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
                p1.setPosition(sf::Vector2f(pos1.x, pos1.y - 1));
            }
        }
        if (pos1.y + 1 < winy-py) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
                p1.setPosition(sf::Vector2f(pos1.x, pos1.y + 1));
            }
        }
        if (pos2.y > 0) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
                p2.setPosition(sf::Vector2f(pos2.x, pos2.y - 1));
            }
        }
        if (pos2.y < winy-py) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
                p2.setPosition(sf::Vector2f(pos2.x, pos2.y + 1));
            }
        }

        //move ball
        auto pos = ball.getPosition();
        ball.setPosition(sf::Vector2f(pos.x + v_ball.get_x(), pos.y + v_ball.get_y()));

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