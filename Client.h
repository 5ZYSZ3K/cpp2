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
        string getName();
        Vehicle* getVehicle(int a);
        void buyVehicleFromFactory(Vehicle* vehicle);
        void buyMotorVehicleFromFactory(MotorVehicle* motorVehicle);
        void buyMotorVehicleFromDealer(MotorVehicle* motorVehicle, double margin);
        void addVehicle(Vehicle* vehicle);
        void addMotorVehicle(MotorVehicle* motorVehicle);
        MotorVehicle* sellMotorVehicle(int a, double b);
        void toString(ostream&);
};