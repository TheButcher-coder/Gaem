#include <iostream>
#include <vector>
#include <map>
#include "src/Card.h"
#include "src/Card_shuffler.h"
#include "src/Field.h"
//Du Figgo

using namespace std;


int main() {
    shared_ptr<Card_shuffler> cs = make_shared<Card_shuffler>();
    Field test(cs);

    test.reveal_card(Pos(1, 1));
    test.reveal_card(Pos(0, 0));

    test.printField();
}