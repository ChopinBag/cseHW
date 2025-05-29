#include "Vehicle.hpp"

using namespace std;

void Vehicle::accelerate() const {
    cout << "The speed of the gv70 has increased by 30 km/h." << endl;
}

void GV70::accelerate() const {
    cout << "The speed of the gv70 has increased by 30 km/h." << endl;
}

void Grandeur::accelerate  () const {
    cout << "The speed of the Grandeur has increased by 20 km/h." << endl;
}

void Carnibal::accelerate  ()const{
    cout << "The speed of the Carnibal has increased by 10 km/h." << endl;
}

unique_ptr<Vehicle> make_vehicle() {
    std::string choice;

    cin >> choice;

    if (choice == "gv70") return make_unique<GV70>();

    else if (choice == "grandeur") return make_unique<Grandeur>();

    else if (choice == "carnibal") return make_unique<Carnibal>();

    else return make_unique<GV70>();
}