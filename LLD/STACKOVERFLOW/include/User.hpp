#ifndef USER_HPP
#define USER_HPP

#include <string>

class User{
    public:
        int id;
        std::string name;
        User(int id, std::string name);
};

#endif