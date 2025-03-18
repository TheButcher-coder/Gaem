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

using namespace std;


class Field {
private:
    vector<vector<shared_ptr<Card>> > cards;
    //shared_ptr<Card_shuffler> cs;    //enthält DEN Card shuffler Es kann nur einen geben, sonst ist die verteilung schlecht
public:
    Field(shared_ptr<Card_shuffler>);
    ~Field() {};

    void printField();
    shared_ptr<Card> get_card(int i, char j);
    void set_card(shared_ptr<Card> in);
    void update();
};



#endif //FIELD_H
