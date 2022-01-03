#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include "Brand.cpp"
#include "VehicleType.cpp"
#include "Bike.cpp"
#include "MotorVehicle.h"
#include "Car.cpp"
#include "MotorCycle.cpp"
#include "MotorVehicle.cpp"
#include <vector>
#include "Factory.cpp"
#include "Dealer.cpp"
#include "Client.cpp"
#include "Painter.cpp"

using namespace std;

bool isNumber(const string& str){
    for (char const &c : str) {
        if (isdigit(c) == 0 && c != '.') return false;
    }
    return true;
}
bool isInteger(const string& str){
    for (char const &c : str) {
        if (isdigit(c) == 0 && c != '.') return false;
    }
    return true;
}

std::vector<std::string> split(std::string str, std::string det){
    std::vector<std::string> v;
    while(str.substr(0, str.find(det)).length() < str.length()){
        v.push_back(str.substr(0, str.find(det)));
        str = str.substr(str.find(det)+1, str.length());
    }
    v.push_back(str.substr(0, str.length()));
    return v;
}

int main(int argc,  char **argv) {
    ifstream in(argv[1]);
    if(argc > 1){
        cin.rdbuf(in.rdbuf());
    }
    vector<Factory> factories;
    vector<Client> clients;
    vector<CarDealer> carDealers;
    Painter painter;
    bool fileDamaged = false;
    ifstream base("baza.txt", std::ofstream::out);
    if(base.is_open()){
        char row[99];
        int pos;
        while(base.getline(row, 99)){
            stringstream ss;
            ss << row;
            string s = ss.str();
            char v;
            if(s == "Factories"){
                pos = -1;
                v = 'f';
            }
            else if (s == "Clients"){
                pos = -1;
                v = 'c';
            }
            else if(s == "CarDealers"){
                pos = -1;
                v = 'd';
            }
            else if(s.at(0) == 'n'){
                pos++;
                if(v == 'f') factories.push_back(*(new Factory(s.substr(2, s.length()))));
                else {
                    vector<string> divided = split(s.substr(2, s.length()), ";");
                    if(divided.size() > 1 && isNumber(divided.at(0))){
                        string name = "";
                        if(v == 'c'){
                            for(int i=1; i<divided.size(); i++) name += divided.at(i);
                            clients.push_back(*(new Client(stod(divided.at(0)), name)));
                        }
                        else if(divided.size() > 2 && isNumber(divided.at(1)) && v == 'd'){
                            for(int i=2; i<divided.size(); i++) name += divided.at(i);
                            carDealers.push_back(*(new CarDealer(stod(divided.at(0)), stod(divided.at(1)),name)));
                        }
                        else{
                            cout << "1" <<endl;
                            cout << s << endl;
                            fileDamaged = true;
                            break;
                        }
                    }
                    else {
                        cout << "2" <<endl;
                        cout << s << endl;
                        fileDamaged = true;
                        break;
                    }
                }
            }
            else if(s != ""){
                vector<string> divided = split(s, ";");
                if(divided.size() >= 4){
                    if(divided.at(0) == "Bike"){
                        bool b;
                        double m;
                        string color = "";
                        if(divided.at(2) == "0") b = false;
                        else if(divided.at(2) == "10.000") b = true;
                        else {
                            cout << "3" <<endl;
                            cout << s << endl;
                            fileDamaged = true;
                            break;
                        }
                        if(isNumber(divided.at(1))) m = stod(divided.at(1));
                        else {
                            cout << "4" <<endl;
                            cout << s << endl;
                            fileDamaged = true;
                            break;
                        }
                        for(int i=3; i<divided.size(); i++){
                            color+=divided.at(i);
                        }
                        Vehicle* vehicle = new Bike(b, color);
                        vehicle->setMileage(m);
                        if(v == 'f') factories.at(pos).addVehicle(vehicle);
                        else if (v == 'c') clients.at(pos).addVehicle(vehicle);
                        else {
                            cout << "5" <<endl;
                            cout << s << endl;
                            fileDamaged = true;
                            break; 
                        }
                    }
                    else if(divided.at(0) == "Motorcycle" || divided.at(0) == "Car"){
                        try{
                            VehicleType type = stringToVehicleType(divided.at(0));
                            Brand brand = stringToBrand(divided.at(1));
                            string color = "";
                            for(int i=4; i<divided.size(); i++){
                                color+=divided.at(i);
                            }
                            double cur = stod(divided.at(2));
                            double mil = stod(divided.at(3));
                            MotorVehicle* motorVehicle = MotorVehicle::createMotorVehicle(type, brand, color);
                            motorVehicle->setCurrentFuelLevel(cur);
                            motorVehicle->setMileage(mil);
                            if(v == 'f') factories.at(pos).addMotorVehicle(motorVehicle);
                            else if(v == 'c') clients.at(pos).addMotorVehicle(motorVehicle);
                            else if(v == 'd') carDealers.at(pos).addMotorVehicle(motorVehicle);
                        }
                        catch(bad_cast e){
                            cout << "7" <<endl;
                            cout << s << endl;
                            fileDamaged = true;
                            break; 
                        }
                        catch(invalid_argument e){
                            cout << "7" <<endl;
                            cout << s << endl;
                            fileDamaged = true;
                            break; 
                        }
                    }
                    else{
                        cout << "8" <<endl;
                        cout << s << endl;
                        fileDamaged = true;
                        break;
                    }
                }
            }
        }
    }
    if(fileDamaged){
        factories.clear();
        clients.clear();
        carDealers.clear();
        cout << "Database has been damaged" << endl;
    }
    bool flag = true;
    while(flag){
        cout << "MENU (pick a number of an option)" << endl;
        cout << "1. Manage factories" << endl;
        cout << "2. Manage clients" << endl;
        cout << "3. Manage car dealers" << endl;
        cout << "4. Quit" << endl;
        string mainOption;
        cin >> mainOption;
        if(mainOption == "1"){
            bool flag2 = true;
            while(flag2){
                string a;
                for(int i=0; i<factories.size(); i++){
                    cout << i+1 << ". " << factories.at(i);
                }
                cout << factories.size()+1 << ". Create new factory" << endl;
                cout << factories.size()+2 << ". Back" << endl;
                cout << "Pick a number:";
                cin >> a;
                cout << endl;
                if(isInteger(a)){
                    int pos = stoi(a);
                    if (pos > 0 && pos <= factories.size()){
                        bool flag3 = true;
                        pos--;
                        while(flag3){
                            string minorOption;
                            cout << "MENU" << endl;
                            cout << "1. List all vehicles" << endl;
                            cout << "2. Create new vehicle" << endl;
                            cout << "3. Delete this factory" << endl;
                            cout << "4. Back" << endl;
                            cout << "Pick a number:";
                            cin >> minorOption;
                            if(minorOption == "1"){
                                for(int i=0; i<factories.at(pos).getMotorVehiclesSize(); i++){
                                    cout << i+1 << ". " << *factories.at(pos).getMotorVehicle(i);
                                }
                                for(int i=0; i<factories.at(pos).getVehiclesSize(); i++){
                                    cout << factories.at(pos).getVehiclesSize()+i+1 << ". " << *factories.at(pos).getVehicle(i);
                                }
                            }
                            else if(minorOption == "2"){
                                cout << "Type in a color name: ";
                                string color;
                                cin >> color;
                                cout << endl;
                                cout << "Possible types: Car, Motorcycle, Bike" << endl;
                                cout << "Type in the vehicle type: ";
                                string typeS;
                                cin >> typeS;
                                cout << endl;
                                try{
                                    VehicleType type = stringToVehicleType(typeS);
                                    if(type == BIKE){
                                        cout << "Type in '1', if you want a basket, and '0', if you don't want a basket: ";
                                        string basket;
                                        cin >> basket;
                                        if (basket == "1") factories.at(pos).createVehicle(true, color);
                                        else if (basket == "0") factories.at(pos).createVehicle(false, color);
                                        else cout << "Wrong value!" << endl;
                                    }
                                    else {
                                        cout << "Possible brands: Bmw, Lamborghini, Mercedes, Audi, Volkswagen" << endl;
                                        cout << "Type in the brand of your vehicle: ";
                                        string brandS;
                                        cin >> brandS;
                                        Brand brand = stringToBrand(brandS);
                                        factories.at(pos).createMotorVehicle(type, brand, color);
                                    }
                                }
                                catch(bad_cast e){
                                    cout << "Wrong brand or vehicle type name!" << endl;
                                }
                                catch(invalid_argument e){
                                    cout << "Wrong value!" << endl;
                                }
                            }
                            else if(minorOption == "3"){
                                factories.erase(factories.begin()+pos);
                                cout << "Deleted!" << endl;
                                flag3 = false;
                            }
                            else if(minorOption == "4"){
                                flag3 = false;
                            }
                            else {
                                cout << "Wrong number!" << endl;
                            }
                        }
                    }
                    else if (pos == factories.size()+1){
                        string name;
                        cout << "Enter name: ";
                        cin >> name;
                        cout << endl;
                        factories.push_back(*(new Factory(name)));
                    }
                    else if (pos == factories.size()+2){
                        flag2 = false;
                    }
                    else cout << "Wrong value!" << endl;
                }
                else cout << "Wrong value!" << endl;
            }
        }
        else if(mainOption == "2"){
            bool flag2 = true;
            while(flag2){
                string a;
                for(int i=0; i<clients.size(); i++){
                    cout << i+1 << ". " << clients.at(i);
                }
                cout << clients.size()+1 << ". Create new client" << endl;
                cout << clients.size()+2 << ". Back" << endl;
                cout << "Pick a number:";
                cin >> a;
                cout << endl;
                if(isInteger(a)){
                    int pos = stoi(a);
                    if (pos > 0 && pos <= clients.size()){
                        bool flag3 = true;
                        pos--;
                        while(flag3){
                            string minorOption;
                            cout << "MENU" << endl;
                            cout << "1. Manage your motor vehicles" << endl;
                            cout << "2. Manage your non-motor vehicles" << endl;
                            cout << "3. Buy a new motor vehicle" << endl;
                            cout << "4. Buy a new non-motor vehicle" << endl;
                            cout << "5. Buy an used vehicle" << endl;
                            cout << "6. Get budget" << endl;
                            cout << "7. Delete this client" << endl;
                            cout << "0. Back" << endl;
                            cin >> minorOption;
                            if(minorOption == "1"){
                                string vehicle;
                                for(int i=0; i<clients.at(pos).getMotorVehiclesSize(); i++){
                                    cout << i+1 << ". " << *clients.at(pos).getMotorVehicle(i);
                                }
                                cout << clients.at(pos).getMotorVehiclesSize()+1 << ". Back" << endl;
                                cout << "Pick an option:";
                                cin >> vehicle;
                                if(isInteger(vehicle)){
                                    int pos2 = stoi(vehicle);
                                    if(pos2 > 0 && pos2 <= clients.at(pos).getMotorVehiclesSize()){
                                        pos2--;
                                        bool flag4 = true;
                                        while(flag4){
                                            cout << "MENU" << endl;
                                            cout << "1. Drive" << endl;
                                            cout << "2. Refuel" << endl;
                                            cout << "3. Get mileage" << endl;
                                            cout << "4. Get current fuel level" << endl;
                                            cout << "5. Get capacity" << endl;
                                            cout << "6. Get color" << endl;
                                            cout << "7. Paint" << endl;
                                            cout << "8. Sell" << endl;
                                            cout << "0. Back" << endl;
                                            string vehicleOption;
                                            cout << "Pick an option:";
                                            cin >> vehicleOption;
                                            cout << endl;
                                            if(isInteger(vehicleOption)){
                                                int pos3 = stoi(vehicleOption);
                                                switch(pos3){
                                                    case 1:
                                                    {
                                                        string distance;
                                                        cout << "Enter the distance:";
                                                        cin >> distance;
                                                        cout << endl;
                                                        if(isNumber(distance)){
                                                            double dist = stod(distance);
                                                            clients.at(pos).getMotorVehicle(pos2)->drive(dist);
                                                        }
                                                        else cout << "Wrong value!" << endl;
                                                    }
                                                    break;
                                                    case 2:
                                                        clients.at(pos).getMotorVehicle(pos2)->refuel();
                                                    break;
                                                    case 3:
                                                        cout << clients.at(pos).getMotorVehicle(pos2)->getMileage() << endl;
                                                    break;
                                                    case 4:
                                                        cout << clients.at(pos).getMotorVehicle(pos2)->getCurrentFuelLevel() << endl;
                                                    break;
                                                    case 5:
                                                        cout << clients.at(pos).getMotorVehicle(pos2)->getCapacity() << endl;
                                                    break;
                                                    case 6:
                                                        cout << clients.at(pos).getMotorVehicle(pos2)->getColor() << endl;
                                                    break;
                                                    case 7:
                                                    {
                                                        cout << "Enter color name: ";
                                                        string col;
                                                        cin >> col;
                                                        painter.changeColorOfVehicle(clients.at(pos).getMotorVehicle(pos2), col);
                                                    }
                                                    break;
                                                    case 8:
                                                    {
                                                        string dealer;
                                                        for(int i=0; i<carDealers.size(); i++){
                                                            cout << i+1 << ". " << carDealers.at(i);
                                                        }
                                                        cout << carDealers.size()+1 << ". Back" << endl;
                                                        cout << "Pick a number:";
                                                        cin >> dealer;
                                                        cout << endl;
                                                        if(isNumber(dealer)){
                                                            int pos4 = stoi(dealer);
                                                            if (pos4 > 0 && pos4 <= carDealers.size()){
                                                                pos4--;
                                                                carDealers.at(pos4).buyMotorVehicle(clients.at(pos).sellMotorVehicle(pos2, carDealers.at(pos4).getBudget()));
                                                            }
                                                            else if (pos4 == carDealers.size()+1) flag4 = false;
                                                            else cout << "Wrong value!";
                                                        }
                                                    }
                                                    break;
                                                    case 0:
                                                        flag4 = false;
                                                    break;
                                                    default:
                                                        cout << "Wrong value!" << endl;
                                                }
                                            }
                                            else cout << "Wrong value!" << endl;
                                        }
                                    }
                                    else if (pos2 == clients.at(pos).getMotorVehiclesSize()+1){
                                        flag3 = false;
                                    }
                                    else cout << "Wrong value!" << endl;
                                }
                                else cout << "Wrong value!" << endl;
                            }
                            else if(minorOption == "2"){
                                string vehicle;
                                for(int i=0; i<clients.at(pos).getVehiclesSize(); i++){
                                    cout << i+1 << ". " << *clients.at(pos).getVehicle(i);
                                }
                                cout << clients.at(pos).getVehiclesSize()+1 << ". Back" << endl;
                                cout << "Pick an option:";
                                cin >> vehicle;
                                if(isInteger(vehicle)){
                                    int pos2 = stoi(vehicle);
                                    if(pos2 > 0 && pos2 <= clients.at(pos).getVehiclesSize()){
                                        pos2--;
                                        bool flag4 = true;
                                        while(flag4){
                                            cout << "MENU" << endl;
                                            cout << "1. Ride" << endl;
                                            cout << "2. Get mileage" << endl;
                                            cout << "3. Get capacity" << endl;
                                            cout << "4. Get price" << endl;
                                            cout << "5. Back" << endl;
                                            string vehicleOption;
                                            cout << "Pick an option:";
                                            cin >> vehicleOption;
                                            cout << endl;
                                            if(isInteger(vehicleOption)){
                                                int pos3 = stoi(vehicleOption);
                                                switch(pos3){
                                                    case 1:
                                                    {
                                                        string distance;
                                                        cout << "Enter the distance:";
                                                        cin >> distance;
                                                        cout << endl;
                                                        if(isNumber(distance)){
                                                            double dist = stod(distance);
                                                            clients.at(pos).getVehicle(pos2)->ride(dist);
                                                        }
                                                        else cout << "Wrong value!" << endl;
                                                    }
                                                    break;
                                                    case 2:
                                                        cout << clients.at(pos).getVehicle(pos2)->getMileage() << endl;
                                                    break;
                                                    case 3:
                                                        cout << clients.at(pos).getVehicle(pos2)->getCapacity() << endl;
                                                    break;
                                                    case 4:
                                                        cout << clients.at(pos).getVehicle(pos2)->getPrice() << endl;
                                                    break;
                                                    case 5:
                                                        flag4 = false;
                                                    break;
                                                    default:
                                                        cout << "Wrong value!" << endl;
                                                }
                                            }
                                            else cout << "Wrong value!" << endl;
                                        }
                                    }
                                    else if (pos2 == clients.at(pos).getVehiclesSize()+1){
                                        flag3 = false;
                                    }
                                    else cout << "Wrong value!" << endl;
                                }
                                else cout << "Wrong value!" << endl;
                            }
                            else if(minorOption == "3"){
                                string factory;
                                for(int i=0; i<factories.size(); i++){
                                    cout << i+1 << ". " << factories.at(i);
                                }
                                cout << factories.size()+1 << ". Back" << endl;
                                cout << "Pick an option:";
                                cin >> factory;
                                if(isInteger(factory)){
                                    int pos2 = stoi(factory);
                                    if(pos2 > 0 && pos2 <= factories.size()){
                                        pos2--;
                                        for(int i=0; i<factories.at(pos2).getMotorVehiclesSize(); i++){
                                            cout << i+1 << ". " << *factories.at(pos2).getMotorVehicle(i);
                                        }
                                        string vehicle;
                                        cout << factories.at(pos2).getMotorVehiclesSize()+1 << ". Back" << endl;
                                        cout << "Pick an option:";
                                        cin >> vehicle;
                                        if(isInteger(vehicle)){
                                            int pos3 = stoi(vehicle);
                                            if(pos3 > 0 && pos3 <= factories.at(pos2).getMotorVehiclesSize()){
                                                pos3--;
                                                clients.at(pos).buyMotorVehicleFromFactory(factories.at(pos2).sellMotorVehicle(pos3, clients.at(pos).getMoney()));
                                                cout << "Bought!" << endl;
                                            }
                                            else if(pos3 == factories.at(pos2).getMotorVehiclesSize()+1){
                                                flag3 = false;
                                            }
                                            else cout << "Wrong value!";
                                        }
                                        else cout << "Wrong value!" << endl;
                                    }
                                    else if(pos2 == factories.size()+1){
                                        flag3 = false;
                                    }
                                    else cout << "Wrong value!" << endl;
                                }
                                else cout << "Wrong value!" << endl;
                            }
                            else if(minorOption == "4"){
                                string factory;
                                for(int i=0; i<factories.size(); i++){
                                    cout << i+1 << ". " << factories.at(i);
                                }
                                cout << factories.size()+1 << ". Back" << endl;
                                cout << "Pick an option:";
                                cin >> factory;
                                if(isInteger(factory)){
                                    int pos2 = stoi(factory);
                                    if(pos2 > 0 && pos2 <= factories.size()){
                                        pos2--;
                                        for(int i=0; i<factories.at(pos2).getVehiclesSize(); i++){
                                            cout << i+1 << ". " << *factories.at(pos2).getVehicle(i);
                                        }
                                        string vehicle;
                                        cout << factories.at(pos2).getVehiclesSize()+1 << ". Back" << endl;
                                        cout << "Pick an option:";
                                        cin >> vehicle;
                                        if(isInteger(vehicle)){
                                            int pos3 = stoi(vehicle);
                                            if(pos3 > 0 && pos3 <= factories.at(pos).getVehiclesSize()){
                                                clients.at(pos).buyVehicleFromFactory(factories.at(pos2).sellVehicle(pos3-1, clients.at(pos).getMoney()));
                                                cout << "Bought!" << endl;
                                            }
                                            else if(pos3 == factories.at(pos).getVehiclesSize()+1){
                                                flag3 = false;
                                            }
                                            else cout << "Wrong value!";
                                        }
                                        else cout << "Wrong value!" << endl;
                                    }
                                    else if(pos2 == factories.size()+1){
                                        flag3 = false;
                                    }
                                    else cout << "Wrong value!" << endl;
                                }
                                else cout << "Wrong value!" << endl;
                            }
                            else if(minorOption == "5"){
                                string dealer;
                                for(int i=0; i<carDealers.size(); i++){
                                    cout << i+1 << ". " << carDealers.at(i);
                                }
                                cout << carDealers.size()+1 << ". Back" << endl;
                                cout << "Pick a number:";
                                cin >> dealer;
                                cout << endl;
                                if(isInteger(dealer)){
                                    int pos2 = stoi(a);
                                    if (pos2 > 0 && pos2 <= carDealers.size()){
                                        pos2--;
                                        string vehicle;
                                        for(int i=0; i<carDealers.at(pos2).getMotorVehiclesSize(); i++){
                                            cout << i+1 << ". " << *carDealers.at(pos2).getMotorVehicle(i);
                                        }
                                        cout << carDealers.at(pos2).getMotorVehiclesSize()+1 << ". Back" << endl;
                                        cout << "Pick an option:";
                                        cin >> vehicle;
                                        if(isInteger(vehicle)){
                                            int pos3 = stoi(vehicle);
                                            if(pos3 > 0 && pos3 <= carDealers.at(pos2).getMotorVehiclesSize()){
                                                pos3--;
                                                clients.at(pos).buyMotorVehicleFromDealer(carDealers.at(pos2).sellMotorVehicle(pos3, clients.at(pos).getMoney()), carDealers.at(pos2).getMargin());
                                            }
                                            else if(pos3 == carDealers.at(pos2).getMotorVehiclesSize()+1) flag3 = false;
                                            else cout << "Wrong value!" << endl;
                                        }
                                    }
                                    else if(pos2 == carDealers.size()+1) flag3 = false;
                                    else cout << "Wrong value!" << endl;
                                }
                            }
                            else if(minorOption == "6") cout << clients.at(pos).getMoney() << endl;
                            else if(minorOption == "7"){
                                clients.erase(clients.begin()+pos);
                                cout << "Deleted!" << endl;
                                flag3 = false;
                            }
                            else if (minorOption == "0"){
                                flag3 = false;
                            }
                            else cout << "Wrong value!" << endl;
                        }
                    }
                    else if (pos == clients.size()+1){
                        string name;
                        cout << "Enter name: ";
                        cin >> name;
                        string moneyS;
                        cout << endl << "Enter the amount of money:";
                        cin >> moneyS;
                        cout << endl;
                        if(isNumber(moneyS)){
                            clients.push_back(*(new Client(stod(moneyS), name)));
                            cout << "Done!" << endl;
                        }
                        else cout << "Wrong value!" << endl;
                    }
                    else if (pos == clients.size()+2){
                        flag2 = false;
                    }
                    else cout << "Wrong value!" << endl;
                }
                else cout << "Wrong value!" << endl;
            }
        }
        else if(mainOption == "3"){
            bool flag2 = true;
            while(flag2){
                string a;
                for(int i=0; i<carDealers.size(); i++){
                    cout << i+1 << ". " << carDealers.at(i);
                }
                cout << carDealers.size()+1 << ". Create new Car Dealer" << endl;
                cout << carDealers.size()+2 << ". Back" << endl;
                cout << "Pick a number:";
                cin >> a;
                cout << endl;
                if(isNumber(a)){
                    int pos = stoi(a);
                    if (pos > 0 && pos <= carDealers.size()){
                        bool flag3 = true;
                        pos--;
                        while(flag3){
                            string minorOption;
                            cout << "MENU" << endl;
                            cout << "1. Manage your vehicles" << endl;
                            cout << "2. Buy an used vehicle" << endl;
                            cout << "3. Get budget" << endl;
                            cout << "4. Delete this car dealer" << endl;
                            cout << "0. Back" << endl;
                            cin >> minorOption;
                            if(minorOption == "1"){
                                string vehicle;
                                for(int i=0; i<carDealers.at(pos).getMotorVehiclesSize(); i++){
                                    cout << i+1 << ". " << *carDealers.at(pos).getMotorVehicle(i);
                                }
                                cout << carDealers.at(pos).getMotorVehiclesSize()+1 << ". Back" << endl;
                                cout << "Pick an option:";
                                cin >> vehicle;
                                if(isInteger(vehicle)){
                                    int pos2 = stoi(vehicle);
                                    if(pos2 > 0 && pos2 <= carDealers.at(pos).getMotorVehiclesSize()){
                                        pos2--;
                                        bool flag4 = true;
                                        while(flag4){
                                            cout << "MENU" << endl;
                                            cout << "1. Drive" << endl;
                                            cout << "2. Refuel" << endl;
                                            cout << "3. Get mileage" << endl;
                                            cout << "4. Get current fuel level" << endl;
                                            cout << "5. Get capacity" << endl;
                                            cout << "6. Get price" << endl;
                                            cout << "7. Sell" << endl;
                                            cout << "8. Back" << endl;
                                            string vehicleOption;
                                            cout << "Pick an option:";
                                            cin >> vehicleOption;
                                            cout << endl;
                                            if(isInteger(vehicleOption)){
                                                int pos3 = stoi(vehicleOption);
                                                switch(pos3){
                                                    case 1:
                                                    {
                                                        string distance;
                                                        cout << "Enter the distance:";
                                                        cin >> distance;
                                                        cout << endl;
                                                        if(isNumber(distance)){
                                                            double dist = stod(distance);
                                                            carDealers.at(pos).getMotorVehicle(pos2)->drive(dist);
                                                        }
                                                        else cout << "Wrong value!" << endl;
                                                    }
                                                    break;
                                                    case 2:
                                                        carDealers.at(pos).getMotorVehicle(pos2)->refuel();
                                                    break;
                                                    case 3:
                                                        cout << carDealers.at(pos).getMotorVehicle(pos2)->getMileage() << endl;
                                                    break;
                                                    case 4:
                                                        cout << carDealers.at(pos).getMotorVehicle(pos2)->getCurrentFuelLevel() << endl;
                                                    break;
                                                    case 5:
                                                        cout << carDealers.at(pos).getMotorVehicle(pos2)->getCapacity() << endl;
                                                    break;
                                                    case 6:
                                                        cout << carDealers.at(pos).getMotorVehicle(pos2)->getPrice() << endl;
                                                    break;
                                                    case 7:
                                                    {
                                                        string client;
                                                        for(int i=0; i<clients.size(); i++){
                                                            cout << i+1 << ". " << clients.at(i);
                                                        }
                                                        cout << clients.size()+1 << ". Back" << endl;
                                                        cout << "Pick a number:";
                                                        cin >> client;
                                                        cout << endl;
                                                        if(isInteger(client)){
                                                            int pos3 = stoi(client);
                                                            if (pos3 > 0 && pos3 <= clients.size()){
                                                                pos3--;
                                                                clients.at(pos3).buyMotorVehicleFromDealer(carDealers.at(pos).sellMotorVehicle(pos2, clients.at(pos3).getMoney()), carDealers.at(pos).getMargin());
                                                            }
                                                            else if (pos3 == carDealers.size()+1) flag4 = false;
                                                            else cout << "Wrong value!";
                                                        }
                                                    }
                                                    break;
                                                    case 8:
                                                        flag4 = false;
                                                    break;
                                                    default:
                                                        cout << "Wrong value!" << endl;
                                                }
                                            }
                                            else cout << "Wrong value!" << endl;
                                        }
                                    }
                                    else if (pos2 == carDealers.at(pos).getMotorVehiclesSize()+1){
                                        flag3 = false;
                                    }
                                    else cout << "Wrong value!" << endl;
                                }
                                else cout << "Wrong value!" << endl;
                            }
                            else if(minorOption == "2"){
                                string client;
                                for(int i=0; i<clients.size(); i++){
                                    cout << i+1 << ". " << clients.at(i);
                                }
                                cout << clients.size()+1 << ". Back" << endl;
                                cout << "Pick a number:";
                                cin >> client;
                                cout << endl;
                                if(isInteger(a)){
                                    int pos2 = stoi(client);
                                    if (pos2 > 0 && pos2 <= clients.size()){
                                        pos2--;
                                        bool flag4 = true;
                                        while(flag4){
                                             string vehicle;
                                            for(int i=0; i<clients.at(pos2).getMotorVehiclesSize(); i++){
                                                cout << i+1 << ". " << *clients.at(pos2).getMotorVehicle(i);
                                            }
                                            cout << clients.at(pos2).getMotorVehiclesSize()+1 << ". Back" << endl;
                                            cout << "Pick an option:";
                                            cin >> vehicle;
                                            if(isInteger(vehicle)){
                                                int pos3 = stoi(vehicle);
                                                if(pos3 > 0 && pos3 <= clients.at(pos2).getMotorVehiclesSize()){
                                                    pos3--;
                                                    carDealers.at(pos).buyMotorVehicle(clients.at(pos2).sellMotorVehicle(pos3, carDealers.at(pos).getBudget()));
                                                    cout << "Done!" << endl;
                                                }
                                                else if (pos3 == clients.at(pos2).getMotorVehiclesSize()+1){
                                                    flag4 = false;
                                                }
                                                else cout << "Wrong value!" << endl;
                                            }
                                        }
                                    }
                                    else if (pos2 == clients.size()+1){
                                        flag3 = false;
                                    }
                                    else cout << "Wrong value!" << endl;
                                }
                            }
                            else if(minorOption == "3") cout << carDealers.at(pos).getBudget() << endl;
                            else if(minorOption == "4"){
                                carDealers.erase(carDealers.begin()+pos);
                                cout << "Deleted!" << endl;
                                flag3 = false;
                            }
                            else if(minorOption == "0"){
                                flag3 = false;
                            }
                        }
                    }
                    else if (pos == carDealers.size()+1){
                        string name;
                        cout << "Enter name: ";
                        cin >> name;
                        string moneyS;
                        cout << endl << "Enter the budget";
                        cin >> moneyS;
                        cout << endl;
                        if(isNumber(moneyS)){
                            string marginS;
                            cout << "Enter the margin:";
                            cin >> marginS;
                            cout << endl;
                            if(isNumber(marginS)){
                                carDealers.push_back(*(new CarDealer(stod(moneyS), stod(marginS), name)));
                                cout << "Done!" << endl;
                            }
                            else cout << "Wrong value!" << endl;
                        }
                        else cout << "Wrong value!" << endl;
                    }
                    else if (pos == carDealers.size()+2){
                        flag2 = false;
                    }
                    else cout << "Wrong value!" << endl;
                }
                else cout << "Wrong value!" << endl;
            }
        }
        else if(mainOption == "4"){
            flag = false;
        }
        else {
            cout << "Wrong value!" << endl;
            cout << mainOption << endl;
            flag = false;
        }
    }
    cout << "Do you want to save changes? Type in '1', if yes, and '2', if no: ";
    string save;
    cin >> save;
    if(save == "1"){
        ofstream save_file("baza.txt");
        save_file <<fixed;
        save_file.precision(3);
        save_file << "Factories" << endl;
        for(Factory f : factories){
            save_file << "n;" << f.getName() << endl;
            for(int i=0; i<f.getMotorVehiclesSize(); i++){
                save_file << f.getMotorVehicle(i)->getType() << ";" << f.getMotorVehicle(i)->getBrandName() << ";" << f.getMotorVehicle(i)->getCurrentFuelLevel() << ";" << f.getMotorVehicle(i)->getMileage() << ";" << f.getMotorVehicle(i)->getColor() << endl;
            }
            for(int i=0; i<f.getVehiclesSize(); i++){
                save_file << "Bike;" << f.getVehicle(i)->getMileage() << ";" << f.getVehicle(i)->getCapacity() << ";" << f.getVehicle(i)->getColor() << endl;
            }
        }
        save_file << "Clients" << endl;
        for(Client f : clients){
            save_file << "n;" << f.getMoney() << ";" << f.getName()  << endl;
            for(int i=0; i<f.getMotorVehiclesSize(); i++){
                save_file << f.getMotorVehicle(i)->getType() << ";" << f.getMotorVehicle(i)->getBrandName() << ";" << f.getMotorVehicle(i)->getCurrentFuelLevel() << ";" << f.getMotorVehicle(i)->getMileage() << ";" << f.getMotorVehicle(i)->getColor() << endl;
            }
            for(int i=0; i<f.getVehiclesSize(); i++){
                save_file << "Bike;" << f.getVehicle(i)->getMileage() << ";" << f.getVehicle(i)->getCapacity() << ";" << f.getVehicle(i)->getColor() << endl;
            }
        }
        save_file << "CarDealers" << endl;
        for(CarDealer f : carDealers){
            save_file << "n;" << f.getBudget() << ";" << f.getMargin() << ";" << f.getName() << endl;
            for(int i=0; i<f.getMotorVehiclesSize(); i++){
                save_file << f.getMotorVehicle(i)->getType() << ";" << f.getMotorVehicle(i)->getBrandName() << ";" << f.getMotorVehicle(i)->getCurrentFuelLevel() << ";" << f.getMotorVehicle(i)->getMileage() << ";" << f.getMotorVehicle(i)->getColor() << endl;
            }
        }
        save_file.close();
        cout << "Data saved!\n";
    }
    else if (save == "2") cout << "Goodbye!";
    else cout << "Ok, discarding";
    return 0;
}