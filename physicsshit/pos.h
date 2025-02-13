//
// Created by Jakub on 13.02.25.
//

#ifndef Pos_H
#define Pos_H

#include<SFML/Graphics.hpp>


class Pos {
private:
    int x;
    int y;

public:
    Pos();
    Pos(int X, int Y);
    Pos(Pos &a);

    int get_x();
    int get_y();
    void set_x(int x);
    void set_y(int y);

    Pos& operator=(Pos &a);
    Pos& operator=(sf::Event::MouseMoved& in);

    Pos &operator=(sf::Event::MouseMoved mouse_moved);
};



#endif //Pos_H
