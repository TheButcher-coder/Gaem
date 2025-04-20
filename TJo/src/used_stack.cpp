//
// Created by Jakub on 25.03.25.
//

#include "used_stack.h"


used_stack::used_stack() {
    cards = std::map<int, int>{};
    history = std::vector<int>{};
}

int used_stack::get_top() {
    return history.at(history.back());
}

void used_stack::take_top() {
    auto back = history.back();
    int val = history.at(back);

    history.pop_back();
    cards[val] -= 1;
}

void used_stack::deposit(int val) {
    history.push_back(val);
    cards[val] += 1;
}


