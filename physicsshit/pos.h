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
    //Pos();
    //Pos(int X, int Y);
    Pos(int x = 0, int y = 0) : x(x), y(y) {} // Default values allow empty constructor
    Pos(sf::Vector2f in);
    Pos(const Pos &a);

    int get_x();
    int get_y();
    void set_x(int x);
    void set_y(int y);

    Pos& operator=(const Pos &a);
    //Pos& operator=(sf::Event::MouseMoved& in);

    Pos &operator=(sf::Event::MouseMoved mouse_moved);
    Pos &operator=(sf::Vector2f in);
    Pos &operator+(const Pos &a);
    Pos &operator-(const Pos &a);

};



#endif //Pos_H
