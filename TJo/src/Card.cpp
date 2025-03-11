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

int Card::get_val() const {
    return val;
}

void Card::set_val(int val) {
    this->val = val;
}