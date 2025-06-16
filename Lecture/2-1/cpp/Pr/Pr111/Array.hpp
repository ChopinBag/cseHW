#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <string>
using namespace std;

template<typename T>
class Array{
    private:
        T* data_;
        size_t size_;
    public:
        Array() = default;
        Array(size_t size)
            : size_(size), data_(new T[size]){};
        ~Array(){delete [] data_;};

        T& at(size_t index){
            if (index >= size_){
                throw out_of_range("Out of Range Error: " + to_string(index));
            }
            return data_[index];
        }
};

#endif