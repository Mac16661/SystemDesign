#include "Game.hpp"
#include "iostream"
using namespace std;

Game::Game(Player p1, Player p2, Board b1) : p1(p1), p2(p2), board(b1), currentPlayer(p1){
    // this->p1 = p1;
    // this->p2 = p2;
    // this->currentPlayer = p1;
    // this->board = b1;
}

void Game::play() {
    while(!board.isBoardEmpty()){
        //change currentPlayer
        if(currentPlayer.getPlayer() == p1.getPlayer()) currentPlayer = p2;
        else currentPlayer = p1;

        int i = -1; int j = -1;
        // take input from current player && check if the move is valid or not
        while(true) {
            
            cout<<"Make sure to enter valid move"<<endl;
            cout<<"Enter Row:: ";
            cin>>i;
            cout<<"\nEnter Col:: ";
            cin>>j;

            if(board.isValidMove(i, j)) {
                break;
            }
        }
        
        // update board
        board.updateBoard(i, j, currentPlayer.getSymbol());

        if(board.isWinningMove(i, j, currentPlayer.getSymbol())) {
            cout<<currentPlayer.getPlayer()<<"  Won the game.\n\n\n";
            break;
        }

        // print board
        board.printBoard();
        
    }

    cout<<"\n\n END OF GAME\n\n\n";
    
}