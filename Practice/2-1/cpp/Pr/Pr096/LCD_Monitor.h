#ifndef LCD_MONITOR_H
#define LCD_MONITOR_H

#include "Monitor.h"
using namespace std;
#include <iostream>

class LCD_Monitor : public Monitor{
    public:
        
        LCD_Monitor(){
            cout << "LCD_Monitor constructor" << endl;
        }
        ~LCD_Monitor(){
            cout << "LCD_Monitor destructor" << endl;
        }
};

#endif