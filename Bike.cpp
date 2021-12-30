#include "Bike.h"

void Bike::ride(double a){
    mileage += a;
    cout << "Bike is riding" << endl;
}
void Bike::toString(std::ostream& os) const {
    if(capacity == 10) os << "Bike with a basket" << endl;
    else os << "Bike with no basket" << endl;
}