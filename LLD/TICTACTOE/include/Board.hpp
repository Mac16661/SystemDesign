#ifndef BOARD_H
#define BOARD_H

#include "bits/stdc++.h"
using namespace std;

class Board{
    private:
        vector<vector<char>> freshBoard;
        int totalMoves; // to calculate if the board is full or not

    public:
        /*
        *Initialize board and totalMoves;
        */
        Board();

        /*
        * Returns the current state of board 
        *
        * @returns: board vector
        */
        vector<vector<char>> getCurrentBoardState(); 

        /*
        * Takes location and symbol as an input, increment totalMove, then mark it with the symbol and return the updated board
        *
        * @param i: ith index to set the players move
        * @param j: jth index to set the players move
        * @param Symbol: player symbol to mark in 2d matrix
        * @returns: updated board vector
        */
        vector<vector<char>> updateBoard(int i, int j, char symbol);  

        /*
        * Takes ith and jth location and checks if the move is valid or not
        *
        * @param i: ith index to set the players move
        * @param j: jth index to set the players move
        * @returns: true if valid move otherwise false
        */
        bool isValidMove(int i, int j);

        /*
        * Checks if the move is winning move or not
        *
        * @param i: ith index to set the players move
        * @param j: jth index to set the players move
        * @param symbol: current player symbol
        * @returns: true if winning move otherwise false
        */
        bool isWinningMove(int i, int j, char symbol);

        /*
        * Checks if the boad still have empty spaces
        *
        * @return: true if board is still empty otherwise false
        */
        bool isBoardEmpty();

        /*
        * Prints the current board state
        */
        void printBoard();

};

#endif