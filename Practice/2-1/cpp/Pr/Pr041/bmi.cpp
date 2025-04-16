// Implement your code

#include "bmi.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

bool addBMI(std::vector<int>& bmis, int weight, int height) {
    bool w_b = (weight > 0);
    bool h_b = (height > 0);

    if (!(w_b & h_b)){
        return false;
    }

    int bmi = 100.0 * (weight * 10000) / (height * height);
    bmis.push_back(bmi);
    return true;
}

bool displayBMIs(const std::vector<int>& bmis) {
    vector<int> dup_bmis = bmis;
    sort(dup_bmis.begin(), dup_bmis.end());
    cout << fixed << setprecision(2);

    for (auto it : dup_bmis){
       cout << static_cast<double>(it) / 100.0 << endl;
    }
    return true; // return for what?
}

bool deleteByValue(std::vector<int>& bmis, int value) {
    auto rp = remove(bmis.begin(),bmis.end(),value);
    bmis.erase(rp,bmis.end());

    return true; // return for what?
}
