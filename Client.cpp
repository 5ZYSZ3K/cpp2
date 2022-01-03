#include "Client.h"

Client::Client(double m, string n){
    money = m;
    name = n;
}
double Client::getMoney(){
    return money;
}
MotorVehicle* Client::getMotorVehicle(int a){
    if (a >=0 && a < motorVehicles.size()) return motorVehicles.at(a);
    else {
        cout << "There is no such vehicle!" << endl;
        return NULL;
    }
}
int Client::getVehiclesSize(){
    return vehicles.size();
}
int Client::getMotorVehiclesSize(){
    return motorVehicles.size();
}
string Client::getName(){
    return name;
}
Vehicle* Client::getVehicle(int a){
    if(a >= 0 && a < vehicles.size()) return vehicles.at(a);
    else {
        cout <<"There is no such vehicle" << endl;
        return NULL;
    }
}
void Client::buyVehicleFromFactory(Vehicle* vehicle){
    if(money >= vehicle->getPrice()){
        money -= vehicle->getPrice();
        vehicles.push_back(vehicle);
    }
    else cout << "You can't afford this vehicle!" << endl;
}
void Client::buyMotorVehicleFromFactory(MotorVehicle* motorVehicle){
    if(money >= motorVehicle->getPrice()){
        money -= motorVehicle->getPrice();
        motorVehicles.push_back(motorVehicle);
    }
    else cout << "You can't afford this vehicle!" << endl;
}
void Client::buyMotorVehicleFromDealer(MotorVehicle* motorVehicle, double margin){
    if(money >= motorVehicle->getPrice()*(1+margin)){
        money -= motorVehicle->getPrice()*(1+margin);
        motorVehicles.push_back(motorVehicle);
    }
    else cout << "You can't afford this vehicle!" << endl;
}
void Client::addVehicle(Vehicle* vehicle){
    vehicles.push_back(vehicle);
}
void Client::addMotorVehicle(MotorVehicle* motorVehicle){
    motorVehicles.push_back(motorVehicle);
}
MotorVehicle* Client::sellMotorVehicle(int a, double b){
    if(a >= 0 && a < motorVehicles.size()){
        MotorVehicle* vehicle = motorVehicles.at(a);
        if(b >= motorVehicles.at(a)->getPrice()){
            money += motorVehicles.at(a)->getPrice();
            motorVehicles.erase(motorVehicles.begin()+a);
        }
        return vehicle;
    }
    else {
        cout << "There is no such vehicle!" << endl;
        return NULL;
    }
}
void Client::toString(ostream& os){
    os << name << endl;
}
std::ostream& operator<<(std::ostream& os,Client& client)
{
    client.toString(os);
    return os;
}