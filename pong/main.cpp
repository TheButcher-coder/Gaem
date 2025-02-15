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
    sf::RenderWindow win(sf::VideoMode({400, 400}), "Pong");

    sf::RectangleShape p1(sf::Vector2f(100, 20));   //Player 1
    sf::RectangleShape p2(sf::Vector2f(100, 20));   //Player 2
    sf::CircleShape ball(static_cast<float>(r));    //Ball

    p1.setPosition(sf::Vector2f(10, 10));
    p2.setPosition(sf::Vector2f(390, 10));
    ball.setPosition(sf::Vector2f(200, 200));

    //Basic window stuff
    while (win.isOpen()) {
        //TEST
        win.clear(sf::Color::Black);

        p1.setFillColor(sf::Color::White);
        p2.setFillColor(sf::Color::White);
        ball.setFillColor(sf::Color(100, 100, 100));

        win.draw(p1);
        win.draw(p2);
        win.draw(ball);
        //if (win.pollEvent()->getIf<sf::Event::Closed>()) win.close();   //close window if close button pressed
        win.display();
    }
}

void airhockeything() {
    //window setup
    sf::RenderWindow win(sf::VideoMode({800, 600}), "airhoggey");
    srand(time(NULL));     //init rnaodm

    int r = 25, n_balls = 10;
    double t, t0=get_millisec();
    std::vector<std::unique_ptr<sf::CircleShape>> balls;    //Ball vektor
    std::vector<std::unique_ptr<Pos>> v_balls;
    //place 10 random Balls
    for (int i = 0; i < n_balls; i++) {
        //Random initial pos
        balls.emplace_back(std::make_unique<sf::CircleShape>(sf::CircleShape(r)));
        balls[i]->setPosition(sf::Vector2f(rand()%(800-r), rand()%(600-r)));
        //init speeds
        v_balls.emplace_back(std::make_unique<Pos>(Pos(1, 1)));
    }
    v_balls[0]->set(1, 1);      //test der bewegung


    while (win.isOpen()) {
        double t1 = get_millisec();
        double t = (t1 - t0) / 1000.0; // In Sekunden umwandeln
        if (t > 1.0) t = 0.016; // Falls `t` zu groß wird, begrenzen (16ms ≈ 60 FPS)
        t0 = t1; // t0 aktualisieren


        //window stuff
        win.clear(sf::Color::White);
        if (win.pollEvent()->getIf<sf::Event::Closed>()) win.close();   //close window

        for (int i = 0; i < n_balls; i++) {
                    //Move balls
                    balls[i]->setPosition(balls[i]->getPosition() + (v_balls[i]->get_v2f())*static_cast<float>(t));
                }

        /*
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
        */



        for (auto& ball:balls) {
            //render each ball
            ball->setFillColor(sf::Color::Red);     //place balls
            win.draw(*ball);
        }
        win.display();
        t0 = t;
        /*
        for (auto& ball:balls) {
            Pos(ball->getPosition()).print();
        }
        */
        std::cout << "ZEIT: " << t << std::endl;
    }
}
int main() {
    std::cout << "POOPER" << std::endl;
    pong();
    return 0;
}