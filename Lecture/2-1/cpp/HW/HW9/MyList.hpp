#ifndef MYLIST_HPP
#define MYLIST_HPP
#include <complex>
#include <algorithm>
#include <iterator>

using namespace std;

// N for maximum size of list
template<typename T, int N>
class MyList{
    public:
        MyList(): data_{new T[N]}, pos_{0}{};
        
        MyList(const MyList& rhs) noexcept
        :data_{new T[N]}, pos_{0}
        {
            copy(rhs.data_, rhs.data_+rhs.pos_, data_);
            pos_ = rhs.pos_;
        };

        MyList& operator=(const MyList& rhs){
            if(this != &rhs){
                T* new_data = new T[N];
                copy(rhs.data_, rhs.data_+rhs.pos_, new_data);
                delete[] data_;
                data_ = new_data;
                pos_ = rhs.pos_;
            }
            return *this;
        };

        void add(T& data){
            if(pos_ < N){
                data_[pos_++] = data;
            }
        };

        void remove(T& data){
            auto it = find(begin(), end(), data);
            if (it != end()){
                for(auto i = it; i < end() - 1; ++i){
                    *i = *(i+1);
                }
                --pos_;
            }
        };

        T* begin() {return data_;}
        const T* begin() const {return data_;}

        T* end() {return data_ + pos_;}
        const T* end() const {return data_ + pos_;}

        ~MyList() noexcept{
            delete[] data_;
        };

    private:
        T* data_;
        int pos_ = 0;
};
#endif 