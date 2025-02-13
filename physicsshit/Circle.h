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
public:
    Circle();
    Circle(Pos p, int r);
    void render(sf::RenderWindow win) override;
};



#endif //CIRCLE_H
