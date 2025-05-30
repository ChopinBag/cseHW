#ifndef OUTPUTDEVICE_H
#define OUTPUTDEVICE_H

using namespace std;
#include <iostream>

class OutputDevice{
    public:
        
        OutputDevice(){
            cout << "OutputDevice constructor" << endl;
        }
        virtual ~OutputDevice(){
            cout << "OutputDevice destructor" << endl;
        }
};

#endif