//
// Created by Jakub on 19.12.25.
//
#include <iostream>
#include "player.h"

using namespace std;

bool player::load(const std::filesystem::path &tileset, unsigned int width, unsigned int height) {
// load the tileset texture
    xs = width;
    ys = height;
    if (!m_tileset.loadFromFile(tileset))   return false;

    auto img = m_tileset.copyToImage();


    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
    m_vertices.resize(width * height * 6);

    // populate the vertex array, with two triangles per tile
    for (unsigned int i = 0; i < width; ++i)
    {
        for (unsigned int j = 0; j < height; ++j)
        {
            // get a pointer to the triangles' vertices of the current tile
            sf::Vertex* triangles = &m_vertices[(i + j * width) * 6];

            // define the 6 corners of the two triangles
            triangles[0].position = sf::Vector2f(i+x, j+y);
            triangles[1].position = sf::Vector2f((i + 1 + x), j+y);
            triangles[2].position = sf::Vector2f(i+x, (j + 1 + y));
            triangles[3].position = sf::Vector2f(i+x, (j + 1 + y) );
            triangles[4].position = sf::Vector2f((i + 1 + x), j+y);
            triangles[5].position = sf::Vector2f((i + 1 + x), (j + 1 + y));



            /*
             i,j    i+1,j
             i,j+1  i+1,j+1
             **/
            //color vertices according to map
            auto color = img.getPixel(sf::Vector2u(i, j));
            auto r = static_cast<int>(color.r);
            //color.a = 0;
            cout << "R: " << static_cast<int>(color.r) << endl << "G: " << endl << static_cast<int>(color.g) << endl << "B: " << static_cast<int>(color.b) << endl << endl;
            triangles[0].color = sf::Color(color);
            triangles[1].color = sf::Color(color);
            triangles[2].color = sf::Color(color);
            triangles[3].color = sf::Color(color);
            triangles[4].color = sf::Color(color);
            triangles[5].color = sf::Color(color);

            triangles[0].texCoords = sf::Vector2f(i+x, j+y);
            triangles[1].texCoords = sf::Vector2f(i+1+x, j+y);
            triangles[2].texCoords = sf::Vector2f(i+x, j+1+y);
            triangles[3].texCoords = sf::Vector2f(i+x, j+1+y);
            triangles[4].texCoords = sf::Vector2f(i+1+x, j+y);
            triangles[5].texCoords = sf::Vector2f(i+1+x, j+1+y);
            }
        }

        return true;
}

void player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &m_tileset;

    // draw the vertex array
    target.draw(m_vertices, states);
}


int player::getx() {
    return x;
    }

int player::gety() {
    return y;
}

sf::Vector2u player::getpos() {
    return sf::Vector2u(x, y);
}

void player::move(int xin, int yin) {
    x = xin;
    y = yin;
}

void player::move(sf::Vector2u moveto) {
    x = moveto.x;
    y = moveto.y;
    m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
    //auto triangles = &m_vertices;
    for (unsigned int i = 0; i < xs; ++i)
    {
        for (unsigned int j = 0; j < ys; ++j)
        {
            // define the 6 corners of the two triangles
            m_vertices[0].position = sf::Vector2f(i+x, j+y);
            m_vertices[1].position = sf::Vector2f((i + 1 + x), j+y);
            m_vertices[2].position = sf::Vector2f(i+x, (j + 1 + y));
            m_vertices[3].position = sf::Vector2f(i+x, (j + 1 + y) );
            m_vertices[4].position = sf::Vector2f((i + 1 + x), j+y);
            m_vertices[5].position = sf::Vector2f((i + 1 + x), (j + 1 + y));

            m_vertices[0].texCoords = sf::Vector2f(i+x, j+y);
            m_vertices[1].texCoords = sf::Vector2f(i+1+x, j+y);
            m_vertices[2].texCoords = sf::Vector2f(i+x, j+1+y);
            m_vertices[3].texCoords = sf::Vector2f(i+x, j+1+y);
            m_vertices[4].texCoords = sf::Vector2f(i+1+x, j+y);
            m_vertices[5].texCoords = sf::Vector2f(i+1+x, j+1+y);
        }
    }

}



