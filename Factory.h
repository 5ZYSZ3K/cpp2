using namespace std;

class Factory{
    private:
        vector<Vehicle*> vehicles;
        vector<MotorVehicle*> motorVehicles;
        string name;
    public:
        Factory(string n);
        void createVehicle(bool b);
        void createMotorVehicle(VehicleType type, Brand brand);
        Vehicle* sellVehicle(int a);
        MotorVehicle* sellMotorVehicle(int a);
        int getVehiclesSize();
        int getMotorVehiclesSize();
        Vehicle* getVehicle(int a);
        MotorVehicle* getMotorVehicle(int a);
        void toString(std::ostream&);
};