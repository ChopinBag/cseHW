#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

#include <iostream>

class complex {
public:
    complex(double real, double imag):r(real),i(imag) {};
    complex(double real): r(real), i(0) {};

    complex add(const complex& c) const {
        return complex(r + c.r, i + c.i);
    }

    friend std::ostream& operator<<(std::ostream& os, const complex& c);

private:
    double r{0}, i{0};
};

std::ostream& operator<<(std::ostream& os, const complex& c) {
    os << c.r << " + " << c.i << "i";
    return os;
}

#endif // COMPLEX_COMPLEX_H
