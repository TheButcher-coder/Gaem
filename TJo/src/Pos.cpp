#include <iostream>
#include "Pos.h"

using namespace std;


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

void Pos::ui_getPos() {
    cout << "Position X: " << endl;
    cin >> x;
    cout << "Position Y: " << endl;
    cin >> y;
}

bool Pos::operator==(const Pos &p) const {
    return x == p.getX() && y == p.getY();
}
