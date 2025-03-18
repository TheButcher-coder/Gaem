#include <iostream>

#include "Player.h"
#include "Card.h"

Player::Player() {
    hand = std::vector<std::vector<Card>>(4, std::vector<Card>(3));
    for (int i=0; i<4; i++) {
        for (int j=0; j<3; j++) {
            // karte ziehen und in hand speichern
            hand[i][j] = Player::drawCard();
        }
    }
    // 2 karten aufdecken
    for (int i=0; i<2; i++) {
        pos pos = getPos();
        // Card.reveal(pos.x, pos.y); oder so
    }
}

Card Player::drawCard() {
    // hier shuffler methode aufrufen 
}

void Player::playCard() {
    // drawCard aufrufen
    // karte ablegen und eigene aufdecken
    // oder karte gegen eigene tauschen
    // je nachdem karte auf ablagestapel
}

struct pos {
    int x;
    int y;
};

pos getPos() {
    pos position = {0, 0};
    std::string input;

    std::cout << "karten koordinaten?: ";
    std::cin >> input;

    position.x = input[0] - 'a';
    position.y = input[1] - '1';
    
    return position;
}