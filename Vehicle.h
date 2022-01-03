class Vehicle {
    protected:
        int capacity;
        double basePrice;
        double mileage;
        string color;
        Vehicle(bool b, string c);
    public:
        virtual void ride(double a) = 0;
        virtual void toString(std::ostream&) const = 0;
        double getMileage();
        double getPrice();
        double getCapacity();
        void changeColor(string c);
        void setMileage(double a);
        string getColor();
};