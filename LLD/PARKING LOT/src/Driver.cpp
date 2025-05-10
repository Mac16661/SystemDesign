#include <typeinfo>
#include "Vehicle.hpp"
#include "ParkingLot.hpp"
using namespace std;

// TODO: Operator overloading
// ostream& operator<<(std::ostream& os, VehicleType type) {
//     switch (type) {
//         case VehicleType::Bike:  os << "Bike"; break;
//         case VehicleType::Car:   os << "Car"; break;
//         case VehicleType::Truck: os << "Truck"; break;
//         default:                 os << "Unknown"; break;
//     }
//     return os;
// }

int main() {
    ParkingLot p = ParkingLot();
     p.getAvailabelSpot();
     Vehicle* car;
    while(true) {
        
        car = new Car("CarXYZ", VehicleType::Car);
        p.bookAvailableSpot(car);
        p.getAvailabelSpot();

    }
    
    return 0;
}