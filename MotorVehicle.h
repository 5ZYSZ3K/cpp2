using namespace std;
class MotorVehicle {
protected:
    Brand brand;
    double currentFuelLevel;
    double maxFuelLevel;
    double mileage;
    double combustion;

    MotorVehicle(Brand a, double b, double d);

public:


    static MotorVehicle *createMotorVehicle(VehicleType type, Brand brand);

    void refuel();
    void drive(double a);
    void cutMileage();
    string getBrandName();

    virtual double getMileage() const = 0;

    virtual double getCurrentFuelLevel() const = 0;

    virtual double getCapacity() const = 0;

    virtual double getPrice() const = 0;

    virtual void toString(std::ostream&) const;

};