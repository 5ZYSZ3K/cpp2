#include "Painter.h"

using namespace std;
template<typename T>
void Painter::changeColorOfVehicle(T motorVehicle, string color){
    motorVehicle->changeColor(color);
    cout << "Painted!" << endl;
}