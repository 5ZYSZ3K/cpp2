#include "Vehicle.cpp"
class Bike : public Vehicle {
    public:
        explicit Bike(bool b, string c) : Vehicle(b, c) {}
        void ride(double a);
        void toString(std::ostream& os) const;
};