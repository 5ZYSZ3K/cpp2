#include "Factory.h"

Factory::Factory(string n){
    name = n;
}
void Factory::createVehicle(bool b, string c){
    vehicles.push_back(new Bike(b, c));
    cout << "Created!" << endl;
}
void Factory::createMotorVehicle(VehicleType type, Brand brand, string co){
    MotorVehicle* vehicle = MotorVehicle::createMotorVehicle(type, brand, co);
    if(vehicle != NULL){
        motorVehicles.push_back(MotorVehicle::createMotorVehicle(type, brand, co));
        cout << "Created!" << endl;
    }
    else cout << "An error occured!" << endl;
}
void Factory::addVehicle(Vehicle* vehicle){
    vehicles.push_back(vehicle);
}
void Factory::addMotorVehicle(MotorVehicle* motorVehicle){
    motorVehicles.push_back(motorVehicle);
}
Vehicle* Factory::sellVehicle(int a, double b){
    if(a >=0 && a < vehicles.size()){
        Vehicle* vehicle = vehicles.at(a);
        if(b >= vehicles.at(a)->getPrice()) vehicles.erase(vehicles.begin()+a);
        return vehicle;
    }
    else{
        cout << "An error occured!" << endl;
        return NULL;
    }
}
MotorVehicle* Factory::sellMotorVehicle(int a, double b){
    if(a >=0 && a < motorVehicles.size()){
        MotorVehicle* motorVehicle = motorVehicles.at(a);
        if(b >= motorVehicles.at(a)->getPrice()) motorVehicles.erase(motorVehicles.begin()+a);
        return motorVehicle;
    }
    else{
        cout << "An error occured!" << endl;
        return NULL;
    }
}
int Factory::getVehiclesSize(){
    return vehicles.size();
}
int Factory::getMotorVehiclesSize(){
    return motorVehicles.size();
}
Vehicle* Factory::getVehicle(int a){
    if(a >= 0 && a < vehicles.size()) return vehicles.at(a);
    else {
        cout <<"There is no such vehicle" << endl;
        return NULL;
    }
}
MotorVehicle* Factory::getMotorVehicle(int a){
    if(a >= 0 && a < motorVehicles.size()) return motorVehicles.at(a);
    else {
        cout <<"There is no such vehicle" << endl;
        return NULL;
    }
}
string Factory::getName(){
    return name;
}
void Factory::toString(ostream& os){
    os << name << " factory" << endl;
}
std::ostream& operator<<(std::ostream& os, Factory& factory)
{
    factory.toString(os);
    return os;
}