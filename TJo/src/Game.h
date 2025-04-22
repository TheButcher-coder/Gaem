#ifndef GAME_H
#define GAME_H
#include <queue>
#include <vector>

#include "Player.h"

class Game {
private:
    std::queue<Player> players;        //first player is the one who plays, gets pushed to back each round
    std::vector<std::vector<int>> scores;    //contains the scores of each player for multiple rounds
    std::shared_ptr<Card_shuffler> cs;

public:
    //Game();
    Game(std::shared_ptr<Card_shuffler> cs_in, int n_players);
    Game(int n_players);
    int getNumPlayers();
    void print_fields();
    void print_scores();
    std::shared_ptr<std::vector<std::vector<int>>>  get_scores();

    void play();        //one round of skyjo
    ~Game()=default;
};
#endif //GAME_H