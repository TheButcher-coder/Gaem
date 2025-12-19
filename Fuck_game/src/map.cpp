//
// Created by Jakub on 19.12.25.
//
#include <iostream>
#include "map.h"

using namespace std;

bool map::load(const std::filesystem::path &tileset, unsigned int width, unsigned int height) {
// load the tileset texture
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
            triangles[0].position = sf::Vector2f(i , j);
            triangles[1].position = sf::Vector2f((i + 1), j );
            triangles[2].position = sf::Vector2f(i, (j + 1));
            triangles[3].position = sf::Vector2f(i , (j + 1) );
            triangles[4].position = sf::Vector2f((i + 1), j);
            triangles[5].position = sf::Vector2f((i + 1), (j + 1));



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

            triangles[0].texCoords = sf::Vector2f(i, j);
            triangles[1].texCoords = sf::Vector2f(i+1, j);
            triangles[2].texCoords = sf::Vector2f(i, j+1);
            triangles[3].texCoords = sf::Vector2f(i, j+1);
            triangles[4].texCoords = sf::Vector2f(i+1, j);
            triangles[5].texCoords = sf::Vector2f(i+1, j+1);
            }
        }

        return true;
}

void map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &m_tileset;

    // draw the vertex array
    target.draw(m_vertices, states);
}

