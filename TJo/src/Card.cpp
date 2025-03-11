//
// Created by Jakub on 11.03.25.
//

#include "Card.h"


Card::Card() {
    val = 0;
}

Card::Card(int val_in) {
    val = val_in;
}

bool Card::get_is_blank() {
    return is_blank;
}

void Card::set_blank(bool v) {
    is_blank = v;
}

int Card::get_val() const {
    return val;
}

void Card::set_val(int val) {
    this->val = val;
}