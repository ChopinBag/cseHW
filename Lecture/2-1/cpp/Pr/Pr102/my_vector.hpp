#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP
#include <initializer_list>
#include <algorithm>

using namespace std;

template<typename T>
class my_vector{
    public:
        explicit my_vector(size_t n=0) noexcept
            :data_{n? new T[n] : nullptr}, size_{n}{}

        my_vector(initializer_list<T> lst) noexcept
            :data_{lst.size() ? new T[lst.size()] : nullptr}, size_{lst.size()}{
                copy(lst.begin(), lst.end(), data_);
                size_ = lst.size();
            }

        my_vector(const my_vector<T>& other) noexcept
        : data_(other.size_ ? new T[other.size_] : nullptr), size_(other.size_)
        {
            for (size_t i = 0; i < size_; ++i)
                data_[i] = other.data_[i];
        }
        
        T& operator[](T i){
            return data_[i];
        }

        size_t size(){
            return size_;
        }

        ~my_vector(){
            delete[] data_;
        }

    private:
        T* data_;
        int size_;
};

#endif