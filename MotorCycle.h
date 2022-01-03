template<int p, int c>
class MotorCycle: public MotorVehicle {
private:
    double capacity = c;
    double basePrice = p;
public:
    explicit MotorCycle(Brand brand, double b, double d, string co) : MotorVehicle(brand, b, d, co) {};
    string getType() const override;
    double getMileage()const override;
    double getPrice() const override;
    double getCapacity()const override;
    void toString(std::ostream& os) const;
    double getCurrentFuelLevel()const override;
};