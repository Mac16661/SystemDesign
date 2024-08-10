#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>

class Display{
    public:
        void showMessage(const std::string& message) {
            std::cout<<message<<std::endl;
        }

        void clearMessage(){
            std::cout<< "------------------------------------\n";
        }
};

#endif