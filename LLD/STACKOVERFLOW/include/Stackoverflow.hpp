#ifndef STACKOVERFLOW_HPP
#define STACKOVERFLOW_HPP

#include "Post.hpp"

#include <vector>
#include <string>
#include <random>

class Stackoverflow{
    std::vector<Post*> posts;
    std::random_device rd;              // seed
    std::mt19937 gen(rd());             // engine
    std::uniform_int_distribution<int> dist(10000, 99999);  // inclusive range


    void postQuestion(std::string question);
    void answerQuestion(std::string answer, int questionID);
    void commentOnAnswer(std::strign comment, int answerID);
    void displayAllPosts();
};

#endif