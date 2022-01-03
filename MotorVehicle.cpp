MotorVehicle *MotorVehicle::createMotorVehicle(VehicleType type, Brand brand, string co) {
    switch (type) {
        case CAR:
            switch(brand){
                case BMW:
                    return new Car<200000,400>(brand, 70, 9, co);
                break;
                case LAMBORGHINI:
                    return new Car<1000000,200>(brand, 100, 12, co);
                break;
                case MERCEDES:
                    return new Car<300000,450>(brand, 80, 10, co);
                break;
                case AUDI:
                    return new Car<50000,600>(brand, 60, 8, co);
                break;
                case VOLKSWAGEN:
                    return new Car<200000,500>(brand, 65, 7, co);
                break;
                default:
                    throw invalid_argument("");
            }
        break;
        case MOTORCYCLE:
            switch(brand){
                case BMW:
                    return new MotorCycle<50000,12>(brand, 20, 4, co);
                break;
                case LAMBORGHINI:
                    return new MotorCycle<300000,15>(brand, 30, 6, co);
                break;
                case MERCEDES:
                    return new MotorCycle<100000,13>(brand, 25, 5, co);
                break;
                case AUDI:
                    return new MotorCycle<10000,8>(brand, 15, 4, co);
                break;
                case VOLKSWAGEN:
                    return new MotorCycle<20000,10>(brand, 18, 3, co);
                break;
                default:
                    throw invalid_argument("");
            }
        break;
        default:
            throw invalid_argument("");
    }
}
void MotorVehicle::toString(std::ostream& os) const {
    os << brandToString(brand) << " with a mileage of " << getMileage() << endl;
}

string MotorVehicle::getBrandName(){
    return brandToString(brand);
}

//przeładowanie operatora wypisywania
std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle)
{
    vehicle.toString(os);
    return os;
}

MotorVehicle::MotorVehicle(Brand a, double b, double d, string co) {
    brand = a;
    currentFuelLevel = b;
    maxFuelLevel = b;
    mileage = 0;
    combustion = d;
    color = co;
}
void MotorVehicle::setCurrentFuelLevel(double a){
    currentFuelLevel = a;
}
void MotorVehicle::setMileage(double a){
    mileage = a;
}
string MotorVehicle::getColor(){
    return color;
}
void MotorVehicle::changeColor(string co){
    color = co;
}
void MotorVehicle::refuel(){
    currentFuelLevel = maxFuelLevel;
    cout << "Car "<<brandToString(brand)<<" is refueled" << endl;
}
void MotorVehicle::drive(double a){
    if (a>0){
        if(currentFuelLevel >= (a/100*combustion)){
            mileage+=a;
            currentFuelLevel-=a/100*combustion;
            cout << brandToString(brand) << " is starting" << endl;
        }
        else {
            cout << brandToString(brand) << " does not have enough fuel" << endl;
        }
    }
    else cout << "Wrong value" << endl;
}
void MotorVehicle::cutMileage(){
    mileage/=2;
}