#ifndef Player_H
#define Player_H

#include <vector>
#include "Card.h"
#include "Card_shuffler.h"
#include "Field.h"
#include "used_stack.h"

class Player {
private:
    Field field;
    std::shared_ptr<Card_shuffler> cs;
    std::shared_ptr<used_stack> us;
    int num;
public:
    //Player();
    Player(std::shared_ptr<Card_shuffler> &cs_in, std::shared_ptr<used_stack> &us, int num_in);
    ~Player()=default;

    Card swapCard(Pos p);
    Card swapCard(Card &c, Pos &p);
    Card swapDiscardedCard(Pos p);
    void playCard();
    void revealCard(Pos &p);

    void print_field();

    bool all_cards_uncovered();

    // 4x3 Matrix with Cards
    //std::vector <std::vector <Card>> hand;
};

#endif //Player_H
