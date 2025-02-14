//
// Created by Jakub on 13.02.25.
//

#include "Pos.h"


Pos::Pos(const Pos &a) {
    *this = a;
}

Pos::Pos(sf::Vector2f in) {
    *this = in;
}


int Pos::get_x() {
    return x;
}
int Pos::get_y() {
    return y;
}

void Pos::set_x(int x) {
    this->x = x;
}
void Pos::set_y(int y) {
    this->y = y;
}

Pos& Pos::operator=(const Pos &a) {
    this->x = a.x;
    this->y = a.y;

    return *this;
}
/*
Pos& Pos::operator=(sf::Event::MouseMoved& in) {
    this->x = in.position.x;
    this->y = in.position.y;

    return *this;
}
*/
Pos &Pos::operator=(sf::Event::MouseMoved mouse_moved) {
    this->x = mouse_moved.position.x;
    this->y = mouse_moved.position.y;

    return *this;
}

Pos &Pos::operator=(sf::Vector2f in) {
    this->x = in.x;
    this->y = in.y;

    return *this;
}

Pos &Pos::operator+(const Pos &a) {
    this->x += a.x;
    this->y += a.y;

    return *this;
}

Pos &Pos::operator-(const Pos &a) {
    this->x -= a.x;
    this->y -= a.y;

    return *this;
}