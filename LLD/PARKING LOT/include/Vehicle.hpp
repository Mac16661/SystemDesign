#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include "iostream"
#include "string"
using namespace std;

enum class VehicleType{
    Bike,
    Car,
    Truck
};

class Vehicle{
    protected:
        string name;
        VehicleType type;
    public:
        Vehicle(string name, VehicleType type);
        string virtual getName() = 0;
        VehicleType virtual getType() = 0;
        virtual ~Vehicle() {}
};

class Car : public Vehicle{
    public:
        Car(string name, VehicleType type);
        string getName();
        VehicleType getType();
};

class Bike : public Vehicle{
    public:
        Bike(string name, VehicleType type);
        string getName();
        VehicleType getType();
};

class Truck : public Vehicle{
    public:
        Truck(string name, VehicleType type);
        string getName();
        VehicleType getType();
};

#endif