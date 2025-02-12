#include <SFML/Graphics.hpp>
#include <iostream>

struct pos {
  int x, y;

  pos(int X, int Y) {
    x = X;
    y = Y;
  }
  pos() {
    x = y = 0;
  }
  pos& operator=(pos& a) {
    x = a.x;
    y = a.y;
    return *this;
  }
};


int main()
{
  // create the window
  sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");
  pos oldpos;
  float r = 100;

  // run the program as long as the window is open
  while (window.isOpen())
  {
    window.clear(sf::Color::White);
    sf::CircleShape shape(r);

    shape.setFillColor(sf::Color(255, 250, 50));
    sf::CircleShape shape2(r);
    shape2.setFillColor(sf::Color(255, 255, 255));
    // check all the window's events that were triggered since the last iteration of the loop
    while (const std::optional event = window.pollEvent())
    {
      if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>()) {
        //update mousepos
        oldpos.x = mouseMoved->position.x;
        oldpos.y = mouseMoved->position.y;
      }
    }
    shape2.setPosition(sf::Vector2f(oldpos.x - r, oldpos.y - r));
    window.draw(shape2);


    window.display();
  }
}