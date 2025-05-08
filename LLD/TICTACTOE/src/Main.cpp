#include<iostream>
#include "Player.hpp"
#include "Board.hpp"
#include "Game.hpp"
using namespace std;

int main() {
    cout<<"TIC TAC TOE\n\n\n";
    Player p1 = Player("mac", 'O');
    cout<<"Player Name :: "<<p1.getPlayer()<<endl;
    cout<<"Player Symbol :: "<<p1.getSymbol()<<endl;

    Player p2 = Player("dac", 'X');
    cout<<"Player Name :: "<<p2.getPlayer()<<endl;
    cout<<"Player Symbol :: "<<p2.getSymbol()<<endl;

    Board b1; 
    Game g1 = Game(p1, p2, b1);
    g1.play();

    return 0;
}