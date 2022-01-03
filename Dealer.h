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
        string getName();
        MotorVehicle* getMotorVehicle(int a);
        void buyMotorVehicle(MotorVehicle* motorVehicle);
        void addMotorVehicle(MotorVehicle* motorVehicle);
        MotorVehicle* sellMotorVehicle(int a, double b);
        int getMotorVehiclesSize();
        void toString(std::ostream&);
};