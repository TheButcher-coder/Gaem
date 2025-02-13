//
// Created by Jakub on 13.02.25.
//

#ifndef POINT_H
#define POINT_H

#include "pos.h"
#include <SFML/Graphics.hpp>

class Point {
private:
    Pos p;

public:
    Point();
    Point(Pos &pin);
    Point(sf::Event::MouseMoved in);

    Pos get_pos();
    void set_pos(Pos in);
    virtual void render(sf::RenderWindow win);
};



#endif //POINT_H
