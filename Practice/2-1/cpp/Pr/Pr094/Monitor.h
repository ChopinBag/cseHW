#ifndef MONITOR_H
#define MONITOR_H

#include "OutputDevice.h"
using namespace std;
#include <iostream>

class Monitor : public OutputDevice{
    public:
        
        Monitor(){
            cout << "Monitor constructor" << endl;
        }
        ~Monitor(){
            cout << "Monitor destructor" << endl;
        }
};

#endif 