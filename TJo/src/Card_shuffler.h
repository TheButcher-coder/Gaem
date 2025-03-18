//
// Created by Jakub on 11.03.25.
//

#ifndef CRAD_SHUFFLER_H
#define CRAD_SHUFFLER_H
#include <vector>


class Card_shuffler {
private:
    std::vector<std::vector<int>> n_cards;  //contains the value in the first row and the number of card in the second row.

public:
    Card_shuffler();
    int draw_card();    //returns Value of drawn Card
};



#endif //CRAD_SHUFFLER_H
