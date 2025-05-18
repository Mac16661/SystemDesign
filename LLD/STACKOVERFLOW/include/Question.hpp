#ifndef QUESTION_HPP
#define QUESTION_HPP

class Question{
    public:
        int id;
        int vote;
        std::string question;

        Question(int id, std::string question);
        void incrementVote();
        void decrementVote();
};

#endif