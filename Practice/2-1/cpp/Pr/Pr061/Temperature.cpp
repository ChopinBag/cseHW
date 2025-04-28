#include "Temperature.h"
#include <sstream>
#include <iomanip>
#include <iostream>


using namespace std;

Temperature::Temperature(double temp, SCALE sc){
    this->temperature = temp;
    this->scale = sc;
}

Temperature Temperature::add(const Temperature& other) const {
    double t;   
    if (scale == other.scale){
        t = temperature + other.temperature;
       } else if(scale == SCALE::CELSIUS){
        t = temperature + other.toCelsius();
       } else{
        t = temperature + other.toFahrenheit();
       }
       Temperature t1(t,scale);
    return t1;
}

string Temperature::print() const{
    stringstream ss;
    ss << fixed << setprecision(1);
    ss << temperature;

    if(scale == SCALE::CELSIUS){
        ss << " C\n"; 
    } else {
        ss << " F\n";
    }

    return ss.str();

}

double Temperature::toCelsius() const {
    return (temperature - 32) * 5 / 9;
}

double Temperature::toFahrenheit() const{
    return temperature * 9/5 + 32;
}