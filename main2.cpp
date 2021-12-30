#include <iostream>
#include <utility>

using namespace std;

//typy pojazdów
enum VehicleType {
    BMW, LAMBORGHINI, MERCEDES
};

//abstrakcyjna klasa pojazdu
class Vehicle {
protected:
    string brand;

    Vehicle(string a) {
        brand = a;
    }

public:


    static Vehicle *createVehicle(VehicleType type);

    virtual void refuel() const = 0;

    virtual void ride() const = 0;

    virtual void toString(std::ostream&) const;

};

//implementacje pojazdu
class Bmw : public Vehicle {
public:
//    explicit Bmw(string brand = "BMW") : Vehicle(std::move(brand)) {}
    explicit Bmw(string brand = "BMW") : Vehicle(brand) {}

    void refuel() const override {
        cout << "Bmw is refueled";
    }

    void ride() const override {
        cout << "Bmw is starting";
    }
};

class Lamborghini : public Vehicle {
public:
    explicit Lamborghini(string brand = "Lamborghini") : Vehicle(brand) {}

    void refuel() const override {
        cout << "Lamborghini is refueled";
    }

    void ride() const override {
        cout << "Lamborghini is starting";
    }
};

class Mercedes : public Vehicle {
public:
    explicit Mercedes(string brand = "Mercedes") : Vehicle(brand) {}

    void refuel() const override {
        cout << "Mercedes is refueled";
    }

    void ride() const override {
        cout << "Mercedes is starting";
    }
};

//fabryka pojazdów
Vehicle *Vehicle::createVehicle(VehicleType type) {
    switch (type) {
        case BMW:
            return new Bmw("BMW");
        case LAMBORGHINI:
            return new Lamborghini("Lamborghini");
        case MERCEDES:
            return new Mercedes("Mercedes");
    }
}

void Vehicle::toString(std::ostream& os) const {
    os << "Printing car " << brand << " in overloaded method" << endl;
}

//przeładowanie operatora wypisywania
std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle)
{
    vehicle.toString(os);
    return os;
}

class Client {
public:
    explicit Client(VehicleType vehicleType) {
        VehicleType type = vehicleType;
        pVehicle = Vehicle::createVehicle(type);
    }

    ~Client() {
        if (pVehicle) {
            delete[] pVehicle;
            pVehicle = NULL;
        }
    }

    Vehicle *getVehicle() {
        return pVehicle;
    }

private:
    Vehicle *pVehicle;
};

int main() {
    string brand;
    VehicleType type;

    cout << "Type car name: " << endl;
    cin >> brand;
    if (brand == "BMW") {
        type = BMW;
    } else if (brand == "Mercedes") {
        type = MERCEDES;
    } else if (brand == "Lamborghini") {
        type = LAMBORGHINI;
    } else {
        cout << "Wrong car name";
        return 0;
    }

    Client *pClient = new Client(type);
    Vehicle *pVehicle = pClient->getVehicle();
    cout << *pVehicle;
    pVehicle->ride();
    pVehicle->refuel();
    return 0;
}