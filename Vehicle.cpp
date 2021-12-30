#include "Vehicle.h"

Vehicle::Vehicle(bool b){
    capacity = b?10:0;
    basePrice = 1000;
    mileage = 0;
}
double Vehicle::getMileage(){
    return mileage;
}
double Vehicle::getPrice(){
    return (basePrice-mileage)>50?basePrice-mileage:50;
}
double Vehicle::getCapacity(){
    return capacity;
}
std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle)
{
    vehicle.toString(os);
    return os;
}