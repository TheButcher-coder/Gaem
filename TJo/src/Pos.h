#ifndef POS_H
#define POS_H

class Pos {
private:
  int x;
  int y;
public:
  // Constructeurs
  Pos();
  Pos(int inx, int iny);

  // Getters
  int getX() const;
  int getY() const;

  // Setters
  void setX(int inx);
  void setY(int iny);

  //UI
  void ui_getPos();

  bool operator==(const Pos &p) const;
};

#endif // POS_H
