//
// Created by Jakub on 13.02.25.
//

#include "Pos.h"

Pos::Pos() {
    x = y = 0;
}

Pos::Pos(Pos &a) {
    *this = a;
}

Pos::Pos(int X, int Y) {
    x = X;
    y = Y;
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

Pos& Pos::operator=(Pos &a) {
    this->x = a.get_x();
    this->y = a.get_y();

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








