#include "MotorCycle.h"

template<int p, int c>
double MotorCycle<p,c>::getCurrentFuelLevel()const{
    return currentFuelLevel;
}
template<int p, int c>
double MotorCycle<p,c>::getCapacity()const{
    return capacity;
}
template<int p, int c>
void MotorCycle<p,c>::toString(std::ostream& os)const{
    os << "MotorCycle " << brandToString(brand) << endl;
}
template<int p, int c>
double MotorCycle<p,c>::getPrice() const {
    return 1000>basePrice-(mileage/20)?1000:basePrice-(mileage/20);
}
template<int p, int c>
double MotorCycle<p,c>::getMileage()const{
    return mileage;
}
template<int p, int c>
string MotorCycle<p,c>::getType()const{
    return "Motorcycle";
}