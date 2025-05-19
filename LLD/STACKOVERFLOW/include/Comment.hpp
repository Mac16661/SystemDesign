#ifndef COMMENT_HPP
#define COMMENT_HPP

#include <string>

class Comment{
    public:
        int id;
        int answerID;
        std::string comment;

        Comment(int id, int answerID, std::string comment);
};

#endif