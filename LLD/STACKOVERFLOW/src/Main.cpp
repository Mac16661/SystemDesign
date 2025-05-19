#include "Stackoverflow.hpp"

int main() {
    Stackoverflow s = Stackoverflow();
    s.postQuestion("What is cpp?");
    s.displayAllPosts();
    s.answerQuestion("C++ is a high level programming language which can kick ass.", 0);
    s.answerQuestion("I can create python with c++ but not the other way around.", 0);
    s.commentOnAnswer("Indeed", 0, 0);
    s.commentOnAnswer("Absolutely right", 0 ,0);
    s.displayAllPosts();
    return 0;
}