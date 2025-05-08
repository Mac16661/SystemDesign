#ifndef PLAYER_H
#define PLAYER_H

#include "string"
using namespace std;

class Player{
    private:
        string name;
        char symbol;
    public:
        Player(string name, char symbol);
        char getSymbol();
        string getPlayer();
};


#endif