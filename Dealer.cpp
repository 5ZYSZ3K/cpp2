#include "Dealer.h"

CarDealer::CarDealer(double b, double m, string n){
    budget = b;
    margin = m;
    name = n;
}
double CarDealer::getBudget(){
    return budget;
}
double CarDealer::getMargin(){
    return margin;
}
MotorVehicle* CarDealer::getMotorVehicle(int a){
    if(a >= 0 && a < motorVehicles.size()) return motorVehicles.at(a);
    else {
        cout <<"There is no such vehicle" << endl;
        return NULL;
    }
}
void CarDealer::buyMotorVehicle(MotorVehicle* motorVehicle){
    if(budget >= motorVehicle->getPrice()){
        budget -= motorVehicle->getPrice();
        if(motorVehicle->getBrandName() == "Audi" || motorVehicle->getBrandName() == "Volkswagen"){
            motorVehicle->cutMileage();
            cout << "Cheater" << endl;
        }
        motorVehicles.push_back(motorVehicle);
    }
    else cout << "You can't afford this vehicle!" << endl;
}
MotorVehicle* CarDealer::sellMotorVehicle(int a){
    if(a >= 0 && a < motorVehicles.size()){
        budget += (1+margin)*motorVehicles.at(a)->getPrice();
        MotorVehicle* vehicle = motorVehicles.at(a);
        motorVehicles.erase(motorVehicles.begin()+a);
        return vehicle;
    }
    else {
        cout << "There is no such vehicle!" << endl;
        return NULL;
    }
}
int CarDealer::getMotorVehiclesSize(){
    return motorVehicles.size();
}
void CarDealer::toString(ostream& os){
    os << name << " car dealer" << endl;
}
std::ostream& operator<<(std::ostream& os, CarDealer& carDealer)
{
    carDealer.toString(os);
    return os;
}