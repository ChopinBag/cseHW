#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP
#include <initializer_list>

using namespace std;

template<typename T>
class my_vector{
    public:
        my_vector(T t=0)
            :data_{t? new T[t] : nullptr}, size_{t}{}

        my_vector(initializer_list<T> lst)
            :data_{lst.size() ? new T[lst.size()] : nullptr}, size_{lst.size()}{}
        
        T& operator[](T i){
            return data_[i];
        }

        int size(){
            return size_;
        }

    private:
        T* data_;
        int size_;
};

#endif