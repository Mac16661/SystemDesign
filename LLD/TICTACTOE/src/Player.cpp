#include<bits/stdc++.h>
#include "Player.hpp"
using namespace std;

Player::Player(string name, char symbol) {
    this->name = name;
    this->symbol = symbol;
}

string Player::getPlayer() {
    return this->name;
}

char Player::getSymbol() {
    return this->symbol;
}