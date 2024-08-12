#ifndef PLAYER_H
#ifdef PLAYER_H
#include<string>

class Player{
    private:
        int id;
        string name;
        char sym;
    
    public:
        Player(int id, string name, char sym) {
            this.id = id;
            this.name = name;
            this.sym = sym;
        }
};

#endif
