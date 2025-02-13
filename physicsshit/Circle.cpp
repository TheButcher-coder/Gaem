//
// Created by Jakub on 13.02.25.
//

#include "Circle.h"

Circle::Circle() {
    //uhhhhh
}

Circle::Circle(Pos pin, int rin) {
    p = pin;
    r = rin;
    c = sf::CircleShape(r);
    c.setPosition(sf::Vector2f(p.get_x(), p.get_y()));

}

Circle::Circle(sf::CircleShape in) {
    r = in.getRadius();
    c = in;
}

void Circle::render(sf::RenderWindow win) {
    win.draw(c);
}
