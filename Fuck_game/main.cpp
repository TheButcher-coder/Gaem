#include <iostream>
#include <SFML/Graphics.hpp>

#include "./src/map.h"

using namespace std;


/*
 This game is an easy Clone of Duck game with a bad name.
 Things it should do:

 - Easy shooting pvp plattformer
 - lighting tests
 - Clean Code (not as the other ones)
 - hopefully be efficient
 - be fun as Fuck!
 - Maybe even some rogue like elements??
 - look good -> Learn to make good pixel art dipshit!!!!!!
 - 320*180 screen px (16:9)
 - Dynamic map movement in that screen (Map should be bigger than resolution

 Optional:
 - Online pvp (idk over ssh or some shit)



 Needed Code things(i think i need):
 - some sort of map class
 - player class
 - wepaons (No need to cathegorize into explosives, one time use or gunz. otu is just 1 ammo, and everything else is just some sort of gun
 Guns need following parameters:(velocity, expl radius, sprite, animation?, )
 - Usables (shit like jetpacks cause they are cool af)
 - sounds (cause farts are funy)


 Player needs:
 - to be drawn -> Drawables from sfml
 - to move
 - to shoot
 - duck
 - DOUBLE JUMP!!!!! (because every game is better with more jumps)
 - to not phase through walls or ground

 Map needs:
 - to look sicK!
 - be fun
 - FUCKING AUTONOMOUS MAP GEN!!!!!! (not like stick fight!)
 - Multiple layers:
    - one layer thats only purpose is to block player movement (can be all Black
    - one top layer for looks
    - one foliage layer
    -first backdrop layer
    - second one
    - and so on

 Guns need:
 - to be shot!
 - to be interesting
 - synergies like weapon craftin would be interesting(idk like items like duct tape you can tape multiple guns together)
 -


 First Steps:
 - Make some sort of map and display it
 - Make some sort of player and move it around map
 - Game Master Class that puts it all together
 -

 */

int main() {
    //test of map with one simple texture as map
    //load texture
    //sf::Texture texture("../sprites/Map/Sprite-0001.png");//, false, sf::IntRect({10, 10}, {10, 10}));
    //texture.setRepeated(true);
    //sf::Sprite sp(texture);


    constexpr std::array level = {
        0
    };

    map tm;
    tm.load("../sprites/Map/Sprite-0001.png", 320, 180);
    //sp.setPosition(sf::Vector2f({25, 25}));
    //sp.setScale(sf::Vector2f({10, 10}));
    //sp.setTextureRect(sf::IntRect({10, 10}, {10, 10}));

    // update the texture from the current contents of the window
    sf::RenderWindow win(sf::VideoMode({320, 180}), "pooper");

    while (win.isOpen()) {
        while (const optional event = win.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                win.close();
        }
        win.clear(sf::Color::Black);
        //win.draw(sp);
        win.draw(tm);
        win.display();
    }

    return 0;
}