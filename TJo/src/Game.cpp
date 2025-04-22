#include "Game.h"

#include "used_stack.h"


Game::Game(std::shared_ptr<Card_shuffler> cs_in, int n_players) {
    cs = cs_in;

    for (int i = 0; i < n_players; i++) {
        //players.push_back(Player(cs));
        players.emplace(cs);        //Geil emplace > push
    }
}

Game::Game(int n_players) {
    cs = make_shared<Card_shuffler>();

    for (int i = 0; i < n_players; i++) {
        players.emplace(cs);
    }
}

void Game::print_fields() {
    int n = getNumPlayers();
    for (int i = 0; i < n; i++) {
        players.front().print_field();

        Player temp = players.front();      //vordersten nach hinten schieben
        players.push(temp);
        players.pop();
    }
}

std::shared_ptr<std::vector<std::vector<int>>> Game::get_scores() {
    return make_shared<std::vector<std::vector<int> >>(scores);
}

void Game::print_scores() {
    int player_nr=1;
    for (auto &player: scores) {
        int  round_nr=1;
        cout << "Player number " << player_nr << ":" << endl;
        for (auto &score: player) {
            cout << "Round number " << round_nr << ": " << score << endl;
            round_nr++;
        }
        player_nr++;
    }
}

int Game::getNumPlayers() {
    int n=0;
    for (auto &player: scores) {
        n++;
    }
    return n;
}

void Game::play() {
    /* One round of skyjo:
     * Start:   each player shows 2 cards
     * Normal Round:    Either:
     *                      - Draw Card and swap with open or closed card -> discard old card
     *                      - Discard drawn card and show one Card in Field
     *
     *                  Special Stuff:
     *                      - 3 Cards of the same number above -> discard all 3. Regularly discarded Card on top
     *
     *                  End:
     *                      - first player to show all Cards starts last round
     *                      -> one last round for every player
     */

    //Start by allowing each player to show 2 Cards
    int n = getNumPlayers();
    for (int i = 0; i < n; i++) {
        Pos p1, p2;
        bool flag=0;    //flag if its the first time asking for Card 2

        p1 = Pos();
        p2 = Pos();

        cout << "Draw 2 Cards: " << endl;
        cout << "Card 1:" << endl;
        p1.ui_getPos();
        do {
            if (flag) cout << "Card 2 cant be the same as 1!" << endl;
            cout << "Card 2:" << endl;
            p2.ui_getPos();

            players.front().revealCard(p1);
            players.front().revealCard(p2);
            players.front().print_field();
            flag = !flag;
        } while (p1 == p2);
    }

    //Normal round
    used_stack us = used_stack();
    bool is_last_round=false;
    do {
            char in;
            do {
                cout << "Draw card from draw pile(A) or discareded pile(B): " << endl;
                cin >> in;
            } while (in != 'A' || in != 'a' || in != 'B' || in != 'b');

            if (in == 'A' || in == 'a') {
                Pos p;
                cout << "Which card should be swapped?" << endl;
                p.ui_getPos();
                us.deposit(player.swapCard(p));
            }
            else {
                Pos p;
                cout << "Which card should be swapped?" << endl;
                p.ui_getPos();
                player.swapDiscardedCard(p);
            }
            //Check if column haS 3 cards of the same value
            //Check if player finished the game

    } while (!is_last_round());
}

