#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include <vector>
#include <memory>

using namespace std;


class Vehicle {
    public:
        Vehicle() = default;
        virtual void accelerate() const = 0;
        ~Vehicle() = default;
};

class GV70 : public Vehicle{
    public : 
        GV70() = default;
        void accelerate() const  override;
        // ~GV70();
};

class Grandeur : public Vehicle{
    public:
        Grandeur() = default;
        void accelerate() const override;
        // ~Grandeur();
};

class Carnibal : public Vehicle{
    public:
        Carnibal() = default;
        void accelerate() const override;
        // ~Carnibal();
};

unique_ptr<Vehicle> make_vehicle();

#endif