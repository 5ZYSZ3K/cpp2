#include "VehicleType.h"
using namespace std;
VehicleType stringToVehicleType(string brand){
    if(brand == "Car"){
        return CAR;
    } else if(brand == "MotorCycle"){
        return MOTORCYCLE;
    } else if (brand == "Bike"){
        return BIKE;
    } else throw 98;
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
            throw 96;
    }
}