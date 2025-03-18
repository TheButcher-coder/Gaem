//
// Created by Jakub on 11.03.25.
//

#ifndef FIELD_H
#define FIELD_H

#include "Card.h"
#include <vector>


using namespace std;


class Field {
private:
    vector<vector<Card> > cards;
public:
    Field();
    ~Field() {};

    void printField();
    void update();
};



#endif //FIELD_H
