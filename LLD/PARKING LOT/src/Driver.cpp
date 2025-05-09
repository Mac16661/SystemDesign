#include <typeinfo>
#include "Vehicle.hpp"
using namespace std;

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

int main() {
    Car c1 = Car("ABC", VehicleType::Car);
    cout<<c1.getName()<<endl;
    // cout<<typeid(c1.getType()).name()<<endl;
    cout << c1.getType() << std::endl;

    
    return 0;
}