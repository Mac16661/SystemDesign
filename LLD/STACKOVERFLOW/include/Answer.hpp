#ifndef ANSWER_HPP
#define ANSWER_HPP

#include <string>

class Answer{
    public:
        int id;
        int vote;
        int questionID;
        std::string answer;

        Answer(int id, int questionID, std::string answer);
        void incrementVote();
        void decrementVote();
};

#endif