using namespace std;

class Client{
    private:
        double money;
        vector<MotorVehicle*> motorVehicles;
        vector<Vehicle*> vehicles;
        string name;
    public:
        Client(double m, string n);
        double getMoney();
        MotorVehicle* getMotorVehicle(int a);
        int getVehiclesSize();
        int getMotorVehiclesSize();
        Vehicle* getVehicle(int a);
        void buyMotorVehicleFromFactory(MotorVehicle* motorVehicle);
        void buyMotorVehicleFromDealer(MotorVehicle* motorVehicle, double margin);
        MotorVehicle* sellMotorVehicle(int a);
        void toString(ostream&);
};