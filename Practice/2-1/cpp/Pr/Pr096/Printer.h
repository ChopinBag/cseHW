#ifndef PRINTER_H
#define PRINTER_H

#include "OutputDevice.h"
#include <iostream>

using namespace std;

class Printer : public OutputDevice{
    public:
        
        Printer(){
            cout << "Printer constructor" << endl;
        }
        ~Printer(){
            cout << "Printer destructor" << endl;
        }
};
#endif 