#ifndef PARKINGLOT_HPP
#define PARKINGLOT_HPP

#include "bits/stdc++.h"
#include "Vehicle.hpp"
using namespace std;

class ParkingLot{
    private:
        vector<vector<Vehicle*>> spot;
    public:
        ParkingLot();
        void getAvailabelSpot();
        bool bookAvailableSpot(Vehicle* type);
        bool releseParkngSpot(int j, VehicleType type);
};

#endif