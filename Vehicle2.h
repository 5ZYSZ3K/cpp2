
using namespace std;

//abstrakcyjna klasa pojazdu
/*class Vehicle {
    protected:
        int capacity;
        double basePrice;
        double mileage;
        Vehicle(bool b){
            capacity = b?10:0;
            basePrice = 1000;
            mileage = 0;
        }

    public:
        virtual void drive();
};

class MotorVehicle{
    protected:
        string brand;
        double currentFuelLevel;
        double maxFuelLevel;
        int capacity;
        VehicleType vehicleType;
        double basePrice;
        double mileage;
        MotorVehicle(Brand brandName, VehicleType type){
            if(type == MOTORCYCLE){
                switch(brandName){
                    case BMW:
                        brand="Bmw";
                        basePrice = 50000;
                        capacity = 12;
                        maxFuelLevel=20;
                    break;
                    case LAMBORGHINI:
                        brand="Lamborghini";
                        basePrice = 300000;
                        capacity = 15;
                        maxFuelLevel=30;
                    break;
                    case MERCEDES:
                        brand="Mercedes";
                        basePrice = 100000;
                        capacity = 13;
                        maxFuelLevel=25;
                    break;
                    case VOLKSWAGEN:
                        brand="VOLKSWAGEN";
                        basePrice = 10000;
                        capacity = 8;
                        maxFuelLevel=15;
                    break;
                    case AUDI:
                        brand="Audi";
                        basePrice = 20000;
                        capacity = 10;
                        maxFuelLevel=18;
                    break;
                }
                vehicleType = MOTORCYCLE;
            }
            else{
                switch(brandName){
                    case BMW:
                        brand="Bmw";
                        basePrice = 200000;
                        capacity = 400;
                        maxFuelLevel=70;
                    break;
                    case LAMBORGHINI:
                        brand="Lamborghini";
                        basePrice = 1000000;
                        capacity = 200;
                        maxFuelLevel=100;
                    break;
                    case MERCEDES:
                        brand="Mercedes";
                        basePrice = 300000;
                        capacity = 450;
                        maxFuelLevel=80;
                    break;
                    case VOLKSWAGEN:
                        brand="VOLKSWAGEN";
                        basePrice = 50000;
                        capacity = 600;
                        maxFuelLevel=60;
                    break;
                    case AUDI:
                        brand="Audi";
                        basePrice = 200000;
                        capacity = 500;
                        maxFuelLevel=65;
                    break;
                }
                vehicleType = CAR;
            }
            mileage = 0;
            currentFuelLevel = maxFuelLevel;
        }
    public:
        void refuel(){
            currentFuelLevel = maxFuelLevel;
            cout << brand << " is refueled" << endl;
        }
        int getMileage(){
            return mileage;
        }
        virtual double getPrice() const = 0;
};

class Bike : public Vehicle {
    public:
        explicit Bike(bool b) : Vehicle(b) {}
        void drive(){
            cout << "Bike is starting" << endl;
        }
        void toString(std::ostream& os) const {
            if(capacity == 10) os << "Bike with a basket" << endl;
            else os << "Bike with no basket" << endl;
        }
};

class MotorCycle : public MotorVehicle {
    public:
        explicit MotorCycle(Brand brandName, VehicleType type = MOTORCYCLE) : MotorVehicle(brandName, type){}
        double getPrice() const override{
            return 1000>basePrice-(mileage/20)?1000:basePrice-(mileage/20);
        }
        void drive(int a){
            if(currentFuelLevel > (a/25)){
                mileage+=a;
                currentFuelLevel-=a/25;
                cout << brand << " is starting" << endl;
            }
            else {
                cout << brand << " does not have enough fuel" << endl;
            }
        }
        void toString(std::ostream& os) const {
            os << "Motorcycle " << brand << endl;
        }
};

class Car : public MotorVehicle {
    public:
        explicit Car(Brand brandName, VehicleType type = CAR) : MotorVehicle(brandName, type){}
        double getPrice() const override{
            return 2000>basePrice-(mileage/10)?2000:basePrice-(mileage/10);
        }
        void drive(int a){
            if(currentFuelLevel > (a/12.5)){
                mileage+=a;
                currentFuelLevel-=a/12.5;
                cout << brand << " is starting" << endl;
            }
            else {
                cout << brand << " does not have enough fuel" << endl;
            }
        }
        void toString(std::ostream& os) const {
            os << "Car " << brand << endl;
        }
};

std::ostream& operator<<(std::ostream& os, const Bike& bike)
{
    bike.toString(os);
    return os;
}

std::ostream& operator<<(std::ostream& os, const MotorCycle& motorcycle)
{
    motorcycle.toString(os);
    return os;
}

std::ostream& operator<<(std::ostream& os, const Car& car)
{
    car.toString(os);
    return os;
}*/