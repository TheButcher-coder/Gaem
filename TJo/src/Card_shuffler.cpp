//
// Created by Jakub on 11.03.25.
//

#include "Card_shuffler.h"
#include <cstdlib>

Card_shuffler::Card_shuffler() {
    //init full stack with standart cards and amounts
    //Custom numbers could be added
    n_cards = std::vector<std::vector<int>>({{-2, 5}, {-1, 10}, {0, 15}, {1, 10}, {2, 10}, {3, 10}, {4, 10}, {5, 10}, {6, 10}, {7, 10}, {8, 10}, {9, 10}, {10, 10}, {11, 10}, {12, 10}});
}

int Card_shuffler::draw_card() {
    //there's cards between 12-> -2 including 0
    int r_num;

    do {    //Find a card thats left in the stack
        r_num = rand()%14;
    } while (n_cards[r_num][1] <= 0);

    n_cards[r_num][1]--;
    return r_num - 2;
}
