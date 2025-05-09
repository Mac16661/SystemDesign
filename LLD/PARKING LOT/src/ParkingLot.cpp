#include "ParkingLot.hpp"
using namesapce std;

// TODO: Operator overloading
ostream& operator<<(std::ostream& os, VehicleType type) {
    switch (type) {
        case VehicleType::Bike:  os << "Bike"; break;
        case VehicleType::Car:   os << "Car"; break;
        case VehicleType::Truck: os << "Truck"; break;
        default:                 os << "Unknown"; break;
    }
    return os;
}

ParkingLot::ParkingLot() {
    spot = vector<vector<Vehicle*>> (3, vector<Vehicle*>(10, nullptr));
}

ParkingLot::getAvailabelSpot(VehicleType type) {
    for(int i=0; i<this->spot.size(); i++){
        for(int j=0; j<this->spot[i].size(); j++) {
            cout<<spot[i][j].getName()<<"::";
            cout<<spot[i][j].getType()<<"         ";
        }

        cout<<endl<<endl;
    }
}

ParkingLot::bookAvailableSpot(Vehicle type) {
    int i=0;
    if (type.getType() == VehicleType::Truck){
        i=0;
    }else if (){
        i=1;
    }else{
        i=2;
    }

    int j=0;

    while(j<this->spot[i].size()){
        if(spot[i][j] != nullptr){
            spot[i][j] = type;
            cout<<"Booked successfull\n\n";
            return true;
        }
    }

    cout<<"No space avaialabe, unsuccessfull\n\n";
    return false;
}

bool ParkingLot::releseParkngSpot(int j, vheicleType type) {
    int i=0;
    if (type.getType() == VehicleType::Truck){
        i=0;
    }else if (){
        i=1;
    }else{
        i=2;
    }

    if(j <this->spot[i].size()){
        cout<<"Released successfull\n\n";
            return true;
    }

    cout<<"Released unsuccessfull\n\n";
    return false;
}