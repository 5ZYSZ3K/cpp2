template<int p, int c>
class MotorCycle: public MotorVehicle {
private:
    double capacity = c;
    double basePrice = p;
public:
    explicit MotorCycle(Brand brand, double b, double d) : MotorVehicle(brand, b, d) {};
    double getMileage()const override;
    double getPrice() const override;
    double getCapacity()const override;
    void toString(std::ostream& os) const;
    double getCurrentFuelLevel()const override;
};