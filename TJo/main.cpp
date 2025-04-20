#include <iostream>
#include <vector>
#include <map>
#include "src/Card.h"
#include "src/Card_shuffler.h"
#include "src/Field.h"
#include "src/Game.h"
//Du Figgo

using namespace std;


int main() {
    shared_ptr<Card_shuffler> cs = make_shared<Card_shuffler>();
    Field test(cs);
    Field t2(cs);

    //test.print();
    //t2.print();

    //new test:
    Game g(4);
    g.print_fields();


    Player p1(cs);

    p1.print_field();
}