//
// Created by Jakub on 22.12.25.
//

#ifndef COLLISION_REC_H
#define COLLISION_REC_H

#include <SFML/Graphics.hpp>



class Collision_rec: public sf::Drawable, public sf::Transformable   {
public:
    sf::VertexArray m_vertices;
    sf::Texture     m_tileset;
    bool load(sf::Vector2u sz, sf::Color c);

    sf::FloatRect getGlobalBounds();
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Vector2u size;
    sf::Color color;

    void set_size(sf::Vector2u inp);
    sf::Vector2u get_size();

    void set_color(sf::Color inp);
    sf::Color get_color();
};



#endif //COLLISION_REC_H
