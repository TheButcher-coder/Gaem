//
// Created by Jakub on 11.03.25.
//

#include "Field.h"

Field::Field(shared_ptr<Card_shuffler> cs) {
    //init playing field by drawing random cards
    //Global card shuffler required
  cards = vector<vector<Card>>(3, vector<Card>(4));

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
        cards[i][j] = cs->draw_card();
      }
    }
}

void Field::printField() {
//print field
    //cout << "";

    for (auto row: cards) {
        for (auto card : row) {
            if (card.is_revealed()) cout << card.get_val() << " | ";
            else cout << " " << " | ";
        }

        cout << endl;
        for (int i = 0; i < 16; i++) {
            cout << "-";
        }
        cout << endl;
    }
}

void Field::update() {
//uuhhhhh
}
