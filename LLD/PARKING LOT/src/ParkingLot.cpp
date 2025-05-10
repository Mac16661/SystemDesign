#include "ParkingLot.hpp"

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
    this->spot = vector<vector<Vehicle*>> (3, vector<Vehicle*>(10, nullptr));
}

void ParkingLot::getAvailabelSpot() {
    for(int i=0; i<this->spot.size(); i++){
        for(int j=0; j<this->spot[i].size(); j++) {
            if(spot[i][j] != nullptr) {
                cout<<spot[i][j]->getName()<<"::";
                cout<<spot[i][j]->getType()<<"         ";
            }else{
                cout<<"*         ";
            }
        }
        cout<<endl<<endl;
    }
}

bool ParkingLot::bookAvailableSpot(Vehicle* vehicle) {
    int i = (vehicle->getType() == VehicleType::Truck) ? 0 :
            (vehicle->getType() == VehicleType::Car)   ? 1 : 2;

    for (int j = 0; j < this->spot[i].size(); ++j) {
        if (spot[i][j] == nullptr) {
            spot[i][j] = vehicle;
            cout << "Booked successfully: " << vehicle->getName() << endl;
            return true;
        }
    }

    cout << "No available spot for " << vehicle->getName() << endl;
    delete vehicle; // avoid memory leak
    return false;
}

bool ParkingLot::releseParkngSpot(int j, VehicleType type) {
    int i=0;
    if (type== VehicleType::Truck){
        i=0;
    }else if (type == VehicleType::Car){
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