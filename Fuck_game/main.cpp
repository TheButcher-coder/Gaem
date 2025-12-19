#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

#include "./src/map.h"
#include "./src/player.h"

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


//FUCK ICH KANN JA ALES MIT SPRITES MACHEN
int main() {
    int x = 320, y = 180;
    //test of map with one simple texture as map
    vector<sf::Drawable*> draw_queue;

    //map init
    map tm;
    draw_queue.push_back(&tm);
    tm.load("../sprites/Map/Sprite-0001.png", x, y);


    //test of one simple char
    player p;
    draw_queue.push_back(&p);
    p.load("../sprites/characters/char1.png", 30, 30);
    // update the texture from the current contents of the window
    sf::RenderWindow win(sf::VideoMode(sf::Vector2u(x, y)), "pooper");

    while (win.isOpen()) {
        while (const optional event = win.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                win.close();
        }
        win.clear(sf::Color::Black);

        //Move char if wsad is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            cout << "Pressed: W" << endl;
            auto pos = p.getpos();
            pos.y += 1;
            p.move(pos);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            cout << "Pressed: S" << endl;
            auto pos = p.getpos();
            pos.y -= 1;
            p.move(pos);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            cout << "Pressed: A" << endl;
            auto pos = p.getpos();
            pos.x -= 1;
            p.move(pos);

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            cout << "Pressed: D" << endl;
            auto pos = p.getpos();
            pos.x += 1;
            p.move(pos);
        }
        cout << "Player pos X: " << p.getpos().x << "; Y: " << p.getpos().y << endl;
        //Draw all objects
        for (auto obj: draw_queue) {
            win.draw(*obj);
        }
        win.display();
    }

    return 0;
}