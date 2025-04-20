#include "Game.h"


Game::Game(std::shared_ptr<Card_shuffler> cs_in, int n_players) {
    cs = cs_in;

    for (int i = 0; i < n_players; i++) {
        players.push_back(Player(cs));
    }
}

Game::Game(int n_players) {
    cs = make_shared<Card_shuffler>();

    for (int i = 0; i < n_players; i++) {
        players.push_back(Player(cs));
    }
}

void Game::print_fields() {
    for (auto &player: players) {
        player.print_field();
    }
}
