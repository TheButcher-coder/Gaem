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
    vector<vector<Card>> cards;
    shared_ptr<Card_shuffler> cs;    //enthält DEN Card shuffler Es kann nur einen geben, sonst ist die verteilung schlecht
public:
    Field(shared_ptr<Card_shuffler>);
    ~Field() {};

    void printField();
    Card get_card(int i, char j);
    void set_card(Card in);
    void update();
};



#endif //FIELD_H

