#ifndef GAME_H
#define GAME_H
#include <vector>

#include "Player.h"

class Game {
private:
    std::vector<Player> players;
    std::shared_ptr<Card_shuffler> cs;

public:
    //Game();
    Game(std::shared_ptr<Card_shuffler> cs_in, int n_players);
    Game(int n_players);
    int getNumPlayers();
    void print_fields();
    ~Game()=default;
};
#endif //GAME_H