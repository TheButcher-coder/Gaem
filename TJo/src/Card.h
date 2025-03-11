//
// Created by Jakub on 11.03.25.
//

#ifndef CARD_H
#define CARD_H



class Card {
private:
  int val;

public:
  Card();
  Card(int val_in);

  int get_val() const;
  void set_val(int val);
};



#endif //CARD_H
