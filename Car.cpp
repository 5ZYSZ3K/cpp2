#include "Car.h"

template<int p, int c>
double Car<p,c>::getCurrentFuelLevel()const{
    return currentFuelLevel;
}
template<int p, int c>
double Car<p,c>::getCapacity()const{
    return capacity;
}
template<int p, int c>
void Car<p,c>::toString(std::ostream& os)const{
    os << "Car " << brandToString(brand) << " with mileage of " << getMileage() << endl;
}
template<int p, int c>
double Car<p,c>::getPrice() const {
    return 2000>basePrice-(mileage/10)?2000:basePrice-(mileage/10);
}
template<int p, int c>
double Car<p,c>::getMileage()const{
    return mileage;
}
template<int p, int c>
string Car<p,c>::getType()const{
    return "Car";
}