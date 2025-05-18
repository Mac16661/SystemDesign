#ifndef POST_HPP
#define POST_HPP

#include <vector>
#include "Question.hpp"
#include "Answer.hpp"
#include "Comment.hpp"
#include "Tag.hpp"


class Post{
    public:
    int id;
        Question question;
        std::vector<Tag> tags;
        std::vector<Answer*> answers;
        std::vector<Comment*> comments;

        Post(int id, const Question& q, const std::vector<Tag>& t);
        void answerQuestion(Answer& ans);
        void commentOnAnswer(Comment& comm);
        void displayPost();
    };

#endif