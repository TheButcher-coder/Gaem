//
// Created by Jakub on 11.03.25.
//

#ifndef FIELD_H
#define FIELD_H

#include "Card.h"
#include "Card_shuffler.h"
#include <vector>
#include <memory>
#include <iostream>
#include <stdlib.h>     //output colors
#include "Pos.h"

using namespace std;


class Field {
private:
    vector<vector<Card>> cards;
    shared_ptr<Card_shuffler> cs;    //enthält DEN Card shuffler Es kann nur einen geben, sonst ist die verteilung schlecht
public:
    Field(shared_ptr<Card_shuffler> cs_in);
    ~Field() = default;

    void print();
    Card get_card(Pos &p);
    void set_card(Card in, Pos p);
    //void update();
    void reveal_card(Pos &p);
    bool all_cards_uncovered();
};



#endif //FIELD_H

