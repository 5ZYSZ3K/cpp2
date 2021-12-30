#include "Vehicle.cpp"
class Bike : public Vehicle {
    public:
        explicit Bike(bool b) : Vehicle(b) {}
        void ride(double a);
        void toString(std::ostream& os) const;
};