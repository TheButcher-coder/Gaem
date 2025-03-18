#ifndef Player_H
#define Player_H

#include <vector>
#include "Card.h"

class Player {
    Player();
    ~Player() {};

    Card drawCard();
    void playCard();


    

    // 4x3 Matrix with Cards
    std::vector <std::vector <Card>> hand;
};

#endif //Player_H
