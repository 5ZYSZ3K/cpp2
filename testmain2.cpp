#include <iostream>
using namespace std;

class Vehicle {
    protected:
        int capacity;
        double basePrice;
        double mileage;
        Vehicle(bool b){ 
            capacity = b?10:0;
            basePrice = 1000;
            mileage = 0;
        };
    public:
        virtual void ride(double a) = 0;
        virtual void toString(std::ostream&) const = 0;
};
class Bike : public Vehicle {
    public:
        explicit Bike(bool b) : Vehicle(b) {};
        void ride(double a){
            mileage += a;
            cout << "Bike is riding" << endl;
        };
        void toString(std::ostream& os) const override {
            if(capacity == 10) os << "Bike with a basket" << endl;
            else os << "Bike with no basket" << endl;
        };
};
int main(){
    Bike* bike = new Bike(false);
    return 0;
}