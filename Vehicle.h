class Vehicle {
    protected:
        int capacity;
        double basePrice;
        double mileage;
        Vehicle(bool b);
    public:
        virtual void ride(double a) = 0;
        virtual void toString(std::ostream&) const = 0;
        double getMileage();
        double getPrice();
        double getCapacity();
};