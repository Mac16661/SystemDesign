#include<bits/stdc++.h>
#include "Board.h"
#include "Player.h"

using namespace std;


int main() {
    Player* p1 = new Player(1, "mac", 'X');
    Player* p2 = new Player(2, "sam", 'O');

    Board* b1 = new Board(0, p1, p2);
    b1.play();

    Board* b1 = new Board(1, p1, p2);
    b1.play();

    return 0;
}