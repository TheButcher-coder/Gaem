//
// Created by Jakub on 13.02.25.
//

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include <SFML/Graphics.hpp>

/*
 *Shits massively undone
 */
class Circle:public Point{
private:
    int r;
    sf::CircleShape c;
public:
    Circle();
    Circle(sf::CircleShape in);
    Circle(Pos pin, int rin);
    void render(sf::RenderWindow win) override;
};



#endif //CIRCLE_H
