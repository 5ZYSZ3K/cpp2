#include <iostream>
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

using namespace std;

bool isNumber(const string& str){
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

int main() {
    vector<Factory> factories;
    factories.push_back(*(new Factory("retarded")));
    factories.at(0).createMotorVehicle(CAR, AUDI);
    factories.at(0).createVehicle(false);
    vector<Client> clients;
    vector<CarDealer> carDealers;
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
                if(isNumber(a)){
                    int pos = stoi(a);
                    if (pos > 0 && pos <= factories.size()){
                        string minorOption;
                        cout << "MENU" << endl;
                        cout << "1. List all vehicles" << endl;
                        cout << "2. Create new vehicle" << endl;
                        cout << "3. Back" << endl;
                        cin >> minorOption;
                        if(minorOption == "1"){
                            pos--;
                            for(int i=0; i<factories.at(pos).getMotorVehiclesSize(); i++){
                                cout << i+1 << ". " << *factories.at(pos).getMotorVehicle(i);
                            }
                            for(int i=0; i<factories.at(pos).getVehiclesSize(); i++){
                                cout << factories.at(pos).getVehiclesSize()+i+1 << ". " << *factories.at(pos).getVehicle(i);
                            }
                        }
                        else if(minorOption == "2"){
                            //do przetestowania
                            cout << "In progress" << endl;
                        }
                        else if(minorOption == "3"){
                            flag2 = false;
                        }
                        else {
                            cout << "Wrong number!" << endl;
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
            // bool flag2 = true;
            // while(flag2){
            //     string minorOption;
            //     cout << "MENU" << endl;
            //     cout << "1. Manage your vehicles" << endl;
            //     cout << "2. Buy a new vehicle" << endl;
            //     cout << "3. Buy an used vehicle" << endl;
            //     cout << "4. Sell a car" << endl;
            //     cout << "5. Back" << endl;
            //     cin >> minorOption;
            //     if(minorOption == "1"){

            //     }
            //     else if(minorOption == "2"){

            //     }
            //     else if (minorOption == "3"){

            //     }
            //     else if(minorOption == "4"){

            //     }
            //     else if(minorOption == "5"){
            //         flag2 = false;
            //     }
            //     else cout << "Wrong value" << endl;
            // }
            cout << "In progress" << endl;
        }
        else if(mainOption == "3"){
            // bool flag2 = true;
            // while(flag2){
            //     string minorOption;
            //     cout << "MENU" << endl;
            //     cout << "1. Buy a vehicle" << endl;
            //     cout << "2. Sell a vehicle" << endl;
            //     cout << "3. Back" << endl;
            //     cin >> minorOption;
            //     if(minorOption == "1"){

            //     }
            //     else if(minorOption == "2"){

            //     }
            //     else if(minorOption == "3"){
            //         flag2 = false;
            //     }
            //     else {
            //         cout << "Wrong number!" << endl;
            //     }
            // }
            cout << "In progress" << endl;
        }
        else if(mainOption == "4"){
            flag = false;
        }
        else {
            cout << "Wrong value!" << endl;
        }
    }
    return 0;
}