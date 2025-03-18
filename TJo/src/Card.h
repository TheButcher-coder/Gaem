//
// Created by Jakub on 11.03.25.
//

#ifndef CARD_H
#define CARD_H



class Card {
private:
  int val;
  bool is_blank;

public:
  Card();     //Constructors
  Card(int val_in);

  bool get_is_blank();  //getters/setters
  void set_blank( bool v);

  int get_val() const;
  void set_val(int val);
};



#endif //CARD_H
