//#include "vehicle_type.cpp"

using namespace std;

class Vehicle {
    protected:
        string brand;
        string vehicleType;

    public:

        explicit Vehicle(VehicleType client_type);

        void refuel();

        void ride();

        void toString(std::ostream&) const;

};