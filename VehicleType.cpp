#include "VehicleType.h"
using namespace std;
VehicleType stringToVehicleType(string brand){
    if(brand == "Car"){
        return CAR;
    } else if(brand == "Motorcycle"){
        return MOTORCYCLE;
    } else if (brand == "Bike"){
        return BIKE;
    } else throw bad_cast();
}

string vehicleTypeToString(VehicleType type){
    switch(type){
        case CAR:
            return "Car";
        break;
        case MOTORCYCLE:
            return "Motorcycle";
        break;
        case BIKE:
            return "Bike";
        break;
        default:
            throw bad_cast();
    }
}