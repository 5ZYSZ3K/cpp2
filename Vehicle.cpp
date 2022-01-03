#include "Vehicle.h"

Vehicle::Vehicle(bool b, string c){
    capacity = b?10:0;
    basePrice = 1000;
    mileage = 0;
    color = c;
}
double Vehicle::getMileage(){
    return mileage;
}
double Vehicle::getPrice(){
    return (basePrice-mileage)>50?basePrice-mileage:50;
}
string Vehicle::getColor(){
    return color;
}
double Vehicle::getCapacity(){
    return capacity;
}
std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle)
{
    vehicle.toString(os);
    return os;
}
void Vehicle::changeColor(string c){
    color = c;
}
void Vehicle::setMileage(double a){
    mileage = a;
}