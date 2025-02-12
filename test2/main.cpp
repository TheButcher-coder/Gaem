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

  // run the program as long as the window is open
  while (window.isOpen())
  {
    // clear the window with black color
    window.clear(sf::Color::White);

    // draw everything here...
    sf::CircleShape shape(50.f);



    shape.setFillColor(sf::Color(100, 250, 50));
    pos oldpos;
    // check all the window's events that were triggered since the last iteration of the loop
    while (const std::optional event = window.pollEvent())
    {
      sf::CircleShape shape2(50.f);
      shape2.setFillColor(sf::Color(100, 100, 100));
      if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
      {
        std::cout << "x: " << mouseMoved->position.x;
        std::cout << "\ty: " << mouseMoved->position.y << std::endl;
        shape2.setPosition(sf::Vector2f(mouseMoved->position.x, mouseMoved->position.y));
        oldpos.x = mouseMoved->position.x;
        oldpos.y =mouseMoved->position.y;
      }
      else {
        shape2.setPosition(sf::Vector2f(oldpos.x, oldpos.y));
      }
      window.draw(shape2);
    }


    //window.draw(shape2);
    // set the shape color to green


    //window.draw(shape);

    // end the current frame


    window.display();
  }
}