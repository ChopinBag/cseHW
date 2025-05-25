#include "Range.hpp"

//Implement your code
Range::Range(long long stop)
: start_{0}, step_{1}, stop_{stop}
{};
Range::Range(long long start, long long stop)
: start_{start}, step_{1}, stop_{stop}
{};
Range::Range(long long start, long long stop, long long step)
: start_{start}, step_{step}, stop_{stop}
{};

Range::Iterator Range::begin() const{
    if(is_empty()){
        return end();
    }
    return Iterator(start_,step_,stop_);
};
Range::Iterator Range::end() const {
    return Iterator(start_,step_,stop_);
};   