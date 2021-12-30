#include "Factory.h"

Factory::Factory(string n){
    name = n;
}
void Factory::createVehicle(bool b){
    vehicles.push_back(new Bike(b));
    cout << "Created!" << endl;
}
void Factory::createMotorVehicle(VehicleType type, Brand brand){
    MotorVehicle* vehicle = MotorVehicle::createMotorVehicle(type, brand);
    if(vehicle != NULL){
        motorVehicles.push_back(MotorVehicle::createMotorVehicle(type, brand));
        cout << "Created!" << endl;
    }
    else cout << "An error occured!" << endl;
}
Vehicle* Factory::sellVehicle(int a){
    if(a >=0 && a < vehicles.size()){
        Vehicle* vehicle = vehicles.at(a);
        vehicles.erase(vehicles.begin()+a);
        return vehicle;
    }
    else{
        cout << "An error occured!" << endl;
        return NULL;
    }
}
MotorVehicle* Factory::sellMotorVehicle(int a){
    if(a >=0 && a < motorVehicles.size()){
        MotorVehicle* motorVehicle = motorVehicles.at(a);
        motorVehicles.erase(motorVehicles.begin()+a);
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
void Factory::toString(ostream& os){
    os << name << " factory" << endl;
}
std::ostream& operator<<(std::ostream& os, Factory& factory)
{
    factory.toString(os);
    return os;
}