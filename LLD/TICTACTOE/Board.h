#ifndef BOARD_H
#define BOARD_H
#include <bits/stdc++.h>
#include "Player.h"
using namespace std;

class Board{
    private:
        int id;
        Player* p1;
        Player* p2;
        Queue<Player> q;
        Player* hasWon;
        bool isDraw;
        vector<vector<char>> board; // Need to initialize 

    public:
        Board(int id,Player  p1, Player p2): hasWon(NULL), isDraw(false) {
            this.id = id;
            this.p1 = p1;
            this.p2 = p2;
            q.push(p1);
            q.push(p2);
        }

        void WinningMove(vector<int> &move, Player p) {
            // check if any player have won using current move
            int row = move[0];
            int col = move[1];
            
            // check vertical
            int cnt = 0;
            for(int i=0; i<board.size(); i++) {
                if(board[i][col] == p.sym){
                    cnt++;
                }
            }

            if(cnt == board.size()-1) {
                hasWon = p;
                return;
            }

            //check horizontal
            cnt  = 0;
            for(int i=0; i<board.size(); i++) {
                if(board[row][i] == p.sym) {
                    cnt++;
                }
            }

            if(cnt == board.size()-1) {
                hasWon = p;
                return;
            }

            // check left diagonal
            cnt = 0;
            int j = 0;
            for(int i=0; i<board.size(); i++) {
                if(board[i][j] == p.sym) {
                    cnt++;
                }
                j++;
            }

            if(cnt == board.size()-1) {
                hasWon = p;
                return;
            }

            // check right diagonal
            cnt = 0;
            int j = board.size()-1;
            for(int i = board.size()-1; i>=0; i--){
                if(board[i][j] == p.sym) {
                    cnt++
                }
                j--;
            }

            if(cnt == board.size()-1) {
                hasWon = p;
                return;
            }

        }

        bool gameDraw(){
            // check if matrix is filled or not
            int cnt=0;
            for(int i=0; i<board.size(); i++){
                for(j=0; j<board[0].size(); j++) {
                    if(board[i][j] == " ") cnt++;
                }
            }
            if (cnt > 0) return false;
            return true;
        }

        vector getValidMove(Player p){
            // Take input from user
            int row,col;

            while(true){
                cout<<"Enter a row b/w 0-8 -> ";
                cin>>row;
                cout<<endl;
                cout<<"Enter a col b/w 0-8 -> ";
                cin>>col;
                cout<<endl;

                if(row>=0 && row<=8 && col>=0 && row <=8 && board[row][col] == " ") {
                    board[row][col] = p.sym;
                    break;
                }else{
                    cout<<"Please Enter a valid move"<<endl;
                }
            }
        }

        void displayBoard() {
            for(int i=0; i<board.size(); i++){
                for(j=0; j<board[0].size(); j++) {
                    cout<<"| "<<board[i][j]<<" |";
                }
                cout<<"______"<<endl;
            }
        }

        void play() {
            // Game logic
            while(hasWon==NULL || !isDraw) {
                displayBoard();

                // Player making move
                Player p = q.front();
                q.pop();

                // Index 0 is row and 1 is col
                vector<int> move = getValidMove(p);

                // Checking if the player can win with this move
                WinningMove(move, p);

                // Checking for draw
                if(gameDraw()) break;

                q.push(p);
            }

            displayBoard();

            if(hasWon != NULL) {
                cout<<"============================================================================================"<<endl;
                cout<<"Player id: " <<hasWon.id<<" Player name: "<<hasWon.name<<" Sym: "<<hasWon.sym>>" has won"<<endl;
                cout<<"============================================================================================"<<endl;

            }else{
                cout<<"============================================================================================"<<endl;
                cout<<" DRAW "<<endl;
                cout<<"============================================================================================"<<endl;
            }
            
        }
};

#endif