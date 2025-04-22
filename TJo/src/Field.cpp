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
    for (auto &row: cards) {
        for (auto &card : row) {
            if (card.is_revealed()) {
                int val = card.get_val();

                if (val <= 5)
                    cout << "\033[32m";  // grün
                else if (val <= 9)
                    cout << "\033[33m";  // gelb
                else
                    cout << "\033[31m";  // rot

                cout << val;

                cout << "\033[0m";  // Farbe zurücksetzen
                cout << " | ";
            }
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

bool Field::all_cards_uncovered() {
    bool ret = true;

    for (auto &column: cards) {
        for (auto &card: column) {
            if (!card.is_revealed()) ret = false;
        }
    }
    return ret;
}
