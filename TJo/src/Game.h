#ifndef GAME_H
#define GAME_H

class Game {
    Game();
    ~Game();

    int getNumPlayers() {
        return numPlayers;
    }

    int numPlayers;
};
#endif //GAME_H