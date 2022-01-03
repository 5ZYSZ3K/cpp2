using namespace std;
class MotorVehicle {
protected:
    Brand brand;
    double currentFuelLevel;
    double maxFuelLevel;
    double mileage;
    double combustion;
    string color;

    MotorVehicle(Brand a, double b, double d, string co);

public:

    static MotorVehicle *createMotorVehicle(VehicleType type, Brand brand, string co);
    void refuel();
    void drive(double a);
    void cutMileage();
    void setCurrentFuelLevel(double a);
    void setMileage(double a);
    string getBrandName();
    string getColor();
    void changeColor(string co);
    virtual string getType() const = 0;
    virtual double getMileage() const = 0;
    virtual double getCurrentFuelLevel() const = 0;
    virtual double getCapacity() const = 0;
    virtual double getPrice() const = 0;
    virtual void toString(std::ostream&) const;
};