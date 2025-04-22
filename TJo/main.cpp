#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

#include "src/Card.h"
#include "src/Card_shuffler.h"
#include "src/Field.h"
#include "src/Game.h"
//Du Figgo

using namespace std;


int main() {
    //Greeting
    int n_players;
    cout << "Welcome to TJo. A terminal based Skyjo implementation!" << endl;
    cout << "How many players are playing?" << endl;
    cin >> n_players;
    Game g(n_players);
    g.play();

}