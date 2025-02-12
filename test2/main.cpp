#include <SFML/Graphics.hpp>
#include <iostream>


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
    sf::CircleShape shape2(50.f);

    shape2.setFillColor(sf::Color(100, 100, 100));
    shape.setFillColor(sf::Color(100, 250, 50));
    // check all the window's events that were triggered since the last iteration of the loop
    while (const std::optional event = window.pollEvent())
    {
      if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
      {
        if (mouseButtonPressed->button == sf::Mouse::Button::Right)
        {
          std::cout << "the right button was pressed" << std::endl;
          std::cout << "mouse x: " << mouseButtonPressed->position.x << std::endl;
          std::cout << "mouse y: " << mouseButtonPressed->position.y << std::endl;
          shape2.setPosition(sf::Vector2f(mouseButtonPressed->position.x, mouseButtonPressed->position.y));
          window.draw(shape2);
        }
      }

    }


    window.draw(shape2);
    // set the shape color to green


    //window.draw(shape);

    // end the current frame


    window.display();
  }
}