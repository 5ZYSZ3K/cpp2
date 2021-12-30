using namespace std;

class CarDealer{
    private:
        vector<MotorVehicle*> motorVehicles;
        double budget;
        double margin;
        string name;
    public:
        CarDealer(double b, double m, string n);
        double getBudget();
        double getMargin();
        MotorVehicle* getMotorVehicle(int a);
        void buyMotorVehicle(MotorVehicle* motorVehicle);
        MotorVehicle* sellMotorVehicle(int a);
        int getMotorVehiclesSize();
        void toString(std::ostream&);
};