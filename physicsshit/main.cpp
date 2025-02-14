#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <chrono>
#include <stdlib.h>
#include <vector>

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

void airhockeything() {
    //window setup
    sf::RenderWindow win(sf::VideoMode({800, 600}), "airhoggey");
    srand(time(NULL));     //init rnaodm

    int r = 25, n_balls = 10;
    std::vector<std::unique_ptr<sf::CircleShape>> balls;    //Ball vektor
    std::vector<std::unique_ptr<Pos>> v_balls;
    //place 10 random Balls
    for (int i = 0; i < n_balls; i++) {
        //Random initial pos
        balls.emplace_back(std::make_unique<sf::CircleShape>(sf::CircleShape(r)));
        balls[i]->setPosition(sf::Vector2f(rand()%(800-r), rand()%(600-r)));

        v_balls.emplace_back(std::make_unique<Pos>(Pos(1, 1)));
    }

    while (win.isOpen()) {
        win.clear(sf::Color::White);
        if (win.pollEvent()->getIf<sf::Event::Closed>()) win.close();   //close window
        for (int i=0; i < n_balls; i++) {
            Pos temp = balls[i]->getPosition();
        }
        for (auto& ball:balls) {
            ball->setFillColor(sf::Color::Red);     //place balls
            win.draw(*ball);
        }

        //Check colissions
        for (int i=0; i < n_balls; i++) {
            for (int j=i+1; j < n_balls; j++) {
                if (balls[i]->getGlobalBounds().findIntersection(balls[j]->getGlobalBounds()).has_value()) {
                    //COLLISION AHEAD!
                    *v_balls[i] = (*v_balls[i] - *v_balls[j]);     //Define - for pos
                    *v_balls[j] = (*v_balls[j] - *v_balls[i]);
                }
            }
        }
        win.display();
    }
    //TODO:
    //mabe balls movable
    //Collisions
}

void falling_circ_TEST() {
    // create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");
    double x, y, t, t0;

    t0 = get_millisec();
    x = 400;

    float r = 50;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        window.clear(sf::Color::White);
        sf::CircleShape shape2(r);

        shape2.setFillColor(sf::Color(0, 0, 0));
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            if (event->getIf<sf::Event::Closed>()) window.close();  //man kann das window schließen yay
        }
        shape2.setOrigin(sf::Vector2f(r, r));   //setzt den Urpsung in die mitte-> kein offset um -r mehr :)
        //calculate ballpos

        t = (get_millisec() - t0)/1000;
        y = 0.5*9.81*t*t;
        std:: cout << "Zeit: " << t << std::endl << "y: " << y << std::endl;

        shape2.setPosition(sf::Vector2f(int(x), int(y)));
        window.draw(shape2);
        window.display();
    }
}

void test() {
    // create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");
    Pos oldpos, p0;
    float r = 50;

    // run the program as long as the window is open

    while (window.isOpen())
    {
        window.clear(sf::Color::White);
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

int main() {
    airhockeything();
    return 0;
}