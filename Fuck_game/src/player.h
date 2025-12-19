//
// Created by Jakub on 19.12.25.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class player: public sf::Drawable, public sf::Transformable  {
private:
    sf::VertexArray m_vertices;
    sf::Texture     m_tileset;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    int x=0, y=0;
    int xs=0, ys=0;


public:
    bool load(const std::filesystem::path &tileset, unsigned int width, unsigned int height);
    void move(int xin, int yin);
    void move(sf::Vector2u moveto);

    int getx();
    int gety();

    sf::Vector2u getpos();
};



#endif //MAP_H
