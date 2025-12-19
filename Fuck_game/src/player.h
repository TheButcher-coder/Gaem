//
// Created by Jakub on 19.12.25.
//

#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>

class player: public sf::Drawable, public sf::Transformable  {
private:
    sf::VertexArray m_vertices;
    sf::Texture     m_tileset;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    int x, y;


public:
    bool load(const std::filesystem::path &tileset, unsigned int width, unsigned int height);
    void move(int x, int y);
    int getx();
    int gety();

};



#endif //MAP_H
