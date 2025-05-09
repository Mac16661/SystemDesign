#ifndef PARKINGLOT_HPP
#define PARKINGLOT_HPP

#include "Vehicle.hpp"
using namespace std;

class ParkingLot{
    private:
        vector<vector<Vehicle*>> spot;
    public:
        ParkingLot();
        void getAvailabelSpot(vheicleType);
        bool bookAvailableSpot(vheicleType);
        bool releseParkngSpot(i, vheicleType);
}

#endif