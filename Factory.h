using namespace std;

class Factory{
    private:
        vector<Vehicle*> vehicles;
        vector<MotorVehicle*> motorVehicles;
        string name;
    public:
        Factory(string n);
        void createVehicle(bool b, string c);
        void createMotorVehicle(VehicleType type, Brand brand, string co);
        void addVehicle(Vehicle* vehicle);
        void addMotorVehicle(MotorVehicle* motorVehicle);
        Vehicle* sellVehicle(int a, double b);
        MotorVehicle* sellMotorVehicle(int a, double b);
        int getVehiclesSize();
        int getMotorVehiclesSize();
        Vehicle* getVehicle(int a);
        MotorVehicle* getMotorVehicle(int a);
        string getName();
        void toString(std::ostream&);
};