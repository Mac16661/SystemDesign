#include "Stackoverflow.hpp"

void Stackoverflow::postQuestion(std::string question, std::string tag) {
    int id = 0;               
    // std::cout <<  << '\n';

    Question q = Question(id, question);
    std::vector<Tag> t;

    t.push_back(Tag(0, id, tag));

    Post* p = new Post(0, q, t);
    posts.push_back(p);
}

void Stackoverflow::answerQuestion(std::string answer, int postID) {
    Answer* a = new Answer(0, 0, answer);
    for(auto p:posts) {
        if(p->id == postID) {
            p->answers.push_back(a);
            return;
        }
    }
}

void Stackoverflow::commentOnAnswer(std::string comment, int postID, int answerID) {
    Comment* c = new Comment(0, answerID, comment);

    for(Post* p : posts) {
        if(p->id == postID) {
            p->comments.push_back(c);
            return;
        }
    }
}

void Stackoverflow::displayAllPosts() {
    for(auto p:posts) {
        p->displayPost();
    }
}