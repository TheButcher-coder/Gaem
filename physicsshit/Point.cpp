//
// Created by Jakub on 13.02.25.
//

#include "Point.h"

Point::Point() {
    Pos temp = Pos();
    this->p = temp;
}

Point::Point(Pos &pin) {
    p = pin;
}

Point::Point(sf::Event::MouseMoved in) {
    p = in;
}

Pos Point::get_pos() {
    return p;
}

void Point::set_pos(Pos in) {
    this->p = in;
}
