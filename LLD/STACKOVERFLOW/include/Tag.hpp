#ifndef TAG_HPP
#define TAG_HPP

#include <string>

class Tag{
    public:
        int id;
        int questionID;
        std::string tag;

        Tag(int id, int questionID, std::string tag);
};

#endif