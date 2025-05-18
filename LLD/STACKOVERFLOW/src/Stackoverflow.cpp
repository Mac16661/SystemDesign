#include "Stackoverflow.hpp"

void Stackoverflow::postQuestion(std::string question, std::string tag="unknown") {
    int id = dist(gen);               
    // std::cout <<  << '\n';

    Question q = Question(id, question);
    std::vector<Tag> t;

    t.push_back(Tag(dist(gen), id, tag));

    Post p = Post(dist(gen), q, t);

}