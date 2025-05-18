#include "Answer.hpp"

Answer::Answer(int id, int questionID, std::string answer) : id(id), questionID(questionID), answer(answer) {};

void Answer::incrementVote() {
    vote++;
}

void Answer::decrementVote() {
    if(vote > 0) vote--;
}