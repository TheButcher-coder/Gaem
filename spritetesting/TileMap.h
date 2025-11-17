//
// Created by Jakub on 17.11.25.
//

#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>


class TileMap: public sf::Drawable, public sf::Transformable {
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::VertexArray m_vertices;
    sf::Texture     m_tileset;


public:
  bool load(const std::filesystem::path& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
};



#endif //TILEMAP_H
