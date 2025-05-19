#ifndef STACKOVERFLOW_HPP
#define STACKOVERFLOW_HPP

#include "Post.hpp"

#include <vector>
#include <string>
#include <random>
#include <iostream>

class Stackoverflow{
    public:
        std::vector<Post*> posts;

        void postQuestion(std::string question, std::string tag="unknown");
        void answerQuestion(std::string answer, int questionID);
        void commentOnAnswer(std::string comment, int postID, int answerID);
        void displayAllPosts();
};

#endif