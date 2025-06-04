#ifndef MYACC_HPP
#define MYACC_HPP

using namespace std;

template<typename T, typename U> U my_accumulate(T begin, T end, U init){
    U ret = init;
    for (T i = begin; i != end; ++i){
        ret += static_cast<U>(*i);
    }
    return ret;
};

#endif 