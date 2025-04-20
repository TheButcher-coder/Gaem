#ifndef Player_H
#define Player_H

#include <vector>
#include "Card.h"
#include "Card_shuffler.h"
#include "Field.h"

class Player {
private:
    Field field;
    std::shared_ptr<Card_shuffler> cs;

public:
    //Player();
    Player(std::shared_ptr<Card_shuffler> &cs_in);
    ~Player()=default;

    Card drawCard();
    void playCard();

    void print_field();
    

    // 4x3 Matrix with Cards
    //std::vector <std::vector <Card>> hand;
};

#endif //Player_H
