#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int num=0;
    cin >> num;

    vector<int> v1;

    for (int i=0; i<num; ++i){
        int n=0;
        cin >> n;
        v1.push_back(n);
    }

    cout << v1[0] << endl;



    sort(begin(v1), end(v1));

    for (int i=0; i< num; ++i){
        cout << v1[i] << " ";
    }

    return 0;
}