#include <iostream>
#include <vector>

#include "src/Card.h"
#include "src/Card_shuffler.h"
//Du Figgo

using namespace std;


int main() {
    Card_shuffler cs;
    for (int i = 0; i < 20; i++) {
        cout << cs.draw_card() << endl;
    }
}