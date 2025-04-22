//
// Created by Jakub on 11.03.25.
//

#include "Field.h"

Field::Field(shared_ptr<Card_shuffler> cs_in) {
    cs = cs_in;
    //init playing field by drawing random cards
    //Global card shuffler required
  cards = vector<vector<Card>>(3, vector<Card>(4));

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
        cards[i][j] = cs->draw_card();
      }
    }
}

void Field::print() {
//print field
    //cout << "";
    for (int i = 0; i < 16; i++) {
        cout << "-";
    }
    cout << endl;
    for (auto row: cards) {
        for (auto card : row) {
            if (card.is_revealed()) cout << card.get_val() << " | ";
            else cout << "?" << " | ";
        }

        cout << endl;
        for (int i = 0; i < 16; i++) {
            cout << "-";
        }
        cout << endl;
    }
}

void Field::reveal_card(Pos &p) {
    cards[p.getX()][p.getY()].reveal();
}

Card Field::get_card(Pos &p) {
    return cards[p.getX()][p.getY()];
}

void Field::set_card(Card in, Pos p) {
    in.reveal();
    cards[p.getX()][p.getY()] = in;
}
