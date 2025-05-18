#include "Question.hpp"

Question::Question(int id, std::string question) : id(id), question(question) {};

void Question::incrementVote() {
    vote++;
}

void Question::decrementVote() {
    if(vote > 0) vote--;
}