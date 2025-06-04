#ifndef LED_MONITOR_H
#define LED_MONITOR_H
#include "Monitor.h"
using namespace std;
#include <iostream>

class LED_Monitor : public Monitor{
    public:
        
        LED_Monitor(){
            cout << "LED_Monitor constructor" << endl;
        }
        ~LED_Monitor(){
            cout << "LED_Monitor destructor" << endl;
        }
};

#endif