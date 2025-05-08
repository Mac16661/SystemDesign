#ifndef GAME_H
#define GAME_H

#include "bits/stdc++.h"
#include "Player.hpp"
#include "Board.hpp"
using namespace std;

class Game{
    private:
        Player p1;
        Player p2;
        Board board;
        Player currentPlayer;
    public:
        Game(Player p1, Player p2, Board board);
        void play();
};

#endif