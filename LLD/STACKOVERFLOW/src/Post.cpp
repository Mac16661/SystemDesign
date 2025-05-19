#include "Post.hpp"
#include <iostream>

Post::Post(int id, const Question& q, const std::vector<Tag>& t) : id(id), question(q) {
    for(auto tag:t) {
        tags.push_back(tag);
    }
};

void Post::answerQuestion(Answer& ans) {
    answers.push_back(&ans);
}

void Post::commentOnAnswer(Comment& comm) {
    comments.push_back(&comm);
}

void Post::displayPost() {
    std::cout<<"=============================================================================================="<<std::endl;
    std::cout<<"ID: "<<question.id<<"\nQuestion: "<<question.question<<std::endl;
    std::cout<<"Tags: "<<std::endl;

    // printing tags
    for(auto t:tags) {
        std::cout<<t.tag<<std::endl;
    }
    std::cout<<"\n\n"<<std::endl;

    // printing answers
    for(auto a:answers) {
        std::cout<<a->id<<": "<<a->answer<<std::endl;

        for(auto c:comments) {
            if(a->id == c->answerID) {
                std::cout<<c->comment<<std::endl;
            }
        }
    }
    std::cout<<"=============================================================================================="<<std::endl;
}