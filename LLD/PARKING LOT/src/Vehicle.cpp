#include "Vehicle.hpp"
using namespace std;

Vehicle::Vehicle(string name, VehicleType type): name(name), type(type) {}


// Implementation of car class
Car::Car(string name, VehicleType type): Vehicle(name, type) {};

string Car::getName(){
    return name;
}

VehicleType Car::getType(){
    return type;
}

// Implementation of bike class


// Implementation of truck class



