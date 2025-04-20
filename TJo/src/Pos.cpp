#include "Pos.h"


Pos::Pos() : x(0), y(0) {}


Pos::Pos(int inx, int iny) : x(inx), y(iny) {}


int Pos::getX() const {
    return x;
}

int Pos::getY() const {
    return y;
}


void Pos::setX(int inx) {
    x = inx;
}

void Pos::setY(int iny) {
    y = iny;
}
