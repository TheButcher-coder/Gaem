//
// Created by Jakub on 19.12.25.
//

#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>

class map: public sf::Drawable, public sf::Transformable  {
private:
  sf::VertexArray m_vertices;
  sf::Texture     m_tileset;

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


public:
    bool load(const std::filesystem::path &tileset, unsigned int width, unsigned int height);
};



#endif //MAP_H
