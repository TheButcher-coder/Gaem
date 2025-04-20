//
// Created by Jakub on 25.03.25.
//

#ifndef USED_STACK_H
#define USED_STACK_H
#include <map>
#include <vector>

#include "Card.h"


class used_stack {
private:
    std::map <int, int> cards;      //<Value, number>
    std::vector<int> history;       //Contains the sequence in which cards got deposited

public:
    used_stack();

    int get_top();
    void take_top();        //or Card take_top()?

    void deposit(int val);




};



#endif //USED_STACK_H
