template<int p, int c>
class Car: public MotorVehicle {
private:
    double capacity = c;
    double basePrice = p;
public:
    explicit Car(Brand brand, double b, double d) : MotorVehicle(brand, b, d) {};
    double getMileage()const override;
    double getPrice() const override;
    double getCapacity()const override;
    void toString(std::ostream& os) const;
    double getCurrentFuelLevel()const override;
};