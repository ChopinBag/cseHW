#ifndef MMU_HPP
#define MMU_HPP
#include <memory>
#include "Student.hpp"

using namespace std;

template<typename T, typename... Args>
unique_ptr<T> my_make_unique(Args&&... args){
    unique_ptr<T> ret(new T(forward<Args>(args)...));
    return ret;
}

#endif