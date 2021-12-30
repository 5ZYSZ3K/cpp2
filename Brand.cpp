using namespace std;
#include "Brand.h"
Brand stringToBrand(string brand){
    if(brand == "Bmw"){
        return BMW;
    } else if(brand == "Lamborghini"){
        return LAMBORGHINI;
    } else if(brand == "Mercedes"){
        return MERCEDES;
    } else if (brand == "Audi"){
        return AUDI;
    } else if (brand == "Volkswagen"){
        return VOLKSWAGEN;
    } else throw 99;
}

string brandToString(Brand brand){
    switch(brand){
        case BMW:
            return "Bmw";
        break;
        case LAMBORGHINI:
            return "Lamborghini";
        break;
        case MERCEDES:
            return "Mercedes";
        break;
        case AUDI:
            return "Audi";
        break;
        case VOLKSWAGEN:
            return "Volkswagen";
        break;
        default:
            throw 97;
    }
}