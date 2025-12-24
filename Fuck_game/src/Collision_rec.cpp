//
// Created by Jakub on 22.12.25.
//

#include "Collision_rec.h"
#include <iostream>


using namespace std;

sf::Vector2u Collision_rec::get_size() { return size; }

void Collision_rec::set_size(sf::Vector2u inp) { size = inp; }

sf::Color Collision_rec::get_color() { return color; }

void Collision_rec::set_color(sf::Color inp) { color = inp; }


bool Collision_rec::load(sf::Vector2u sz, sf::Color c) {
    color = c;
    size = sz;

    if (!m_tileset.resize(sz))
        return false;

    int width = size.x, height = size.y;

    int x = width, y = height;
    // get a pointer to the triangles' vertices of the current tile
    m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
    m_vertices.resize(6);

    // auto triangles = &m_vertices;

    // define the 6 corners of the two triangles

    m_vertices[0].position = sf::Vector2f(0, 0);
    m_vertices[1].position = sf::Vector2f(x, 0);
    m_vertices[2].position = sf::Vector2f(0, y);
    m_vertices[3].position = sf::Vector2f(0, y);
    m_vertices[4].position = sf::Vector2f(x, 0);
    m_vertices[5].position = sf::Vector2f(x, y);


    /*
     i,j    i+1,j
     i,j+1  i+1,j+1
     **/
    // color vertices according to map
    // auto color = img.getPixel(sf::Vector2u(i, j));
    // auto r = static_cast<int>(color.r);
    // color.a = 0;
    // cout << "R: " << static_cast<int>(color.r) << endl << "G: " << endl << static_cast<int>(color.g) << endl << "B: "
    // << static_cast<int>(color.b) << endl << endl;
    m_vertices[0].color = color;
    m_vertices[1].color = color;
    m_vertices[2].color = color;
    m_vertices[3].color = color;
    m_vertices[4].color = color;
    m_vertices[5].color = color;

    m_vertices[0].texCoords = sf::Vector2f(0, 0);
    m_vertices[1].texCoords = sf::Vector2f(x, 0);
    m_vertices[2].texCoords = sf::Vector2f(0, y);
    m_vertices[3].texCoords = sf::Vector2f(0, y);
    m_vertices[4].texCoords = sf::Vector2f(x, 0);
    m_vertices[5].texCoords = sf::Vector2f(x, y);

    return true;
}


void Collision_rec::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = nullptr;

    // draw the vertex array
    target.draw(m_vertices, states);
}

sf::FloatRect Collision_rec::getGlobalBounds() {
    sf::Vector2f pos = getPosition();
    sf::FloatRect bounds = m_vertices.getBounds();

    bounds.position = pos;
    return bounds;
}
