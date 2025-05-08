#include "Board.hpp"

Board::Board(){
    this->freshBoard = vector<vector<char>>(3, vector<char>(3, ' '));
    this->totalMoves = 0;
}

vector<vector<char>> Board::getCurrentBoardState(){
    return this->freshBoard;
}

vector<vector<char>> Board::updateBoard(int i, int j, char symbol){

    this->freshBoard[i][j] = symbol;
    this->totalMoves++;
    return this->freshBoard;
}

bool Board::isValidMove(int i, int j) {
    if(i<0 || j<0 || i>= this->freshBoard.size()|| j>= this->freshBoard[0].size()) return false;
    if(this->freshBoard[i][j] == ' ') return true;
    return false;
}

bool Board::isBoardEmpty(){
    return this->totalMoves==9;
}

bool Board::isWinningMove(int i, int j, char symbol) {
    //check horizontal
    int count=0;
    for(int k=0; k < this->freshBoard[i].size(); k++){
        if(freshBoard[i][k] == symbol) count++;
    }

    if(count == 3) return true;
    else count = 0;

    //chekc vertical
    for(int k=0; k<this->freshBoard.size(); k++) {
        if(freshBoard[k][j] == symbol) count++;
    }

    if(count == 3) return true;
    else count = 0;

    //check right diagonal 
    i=0;
    j=0;

    while(i<this->freshBoard.size() && j<this->freshBoard[0].size()){
        if(this->freshBoard[i][j] == symbol) count++;
        i++;
        j++;
    }

    if(count == 3) return true;
    else count = 0;

    //check left diagonal
    i=this->freshBoard.size();
    j=this->freshBoard[0].size();

    while(i<=0 && j<=0){
        if(this->freshBoard[i][j] == symbol) count++;
        i--;
        j--;
    }

    if(count == 3) return true;
    return false;
}

void Board::printBoard(){
    for(int i=0; i<this->freshBoard.size(); i++){
        for(int j=0; j<this->freshBoard[i].size(); j++){
            cout<<this->freshBoard[i][j]<<"  ";
        }
        cout<<endl;
    }
}


