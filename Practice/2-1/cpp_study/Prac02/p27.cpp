#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int vec_size = 0;
    cin >> vec_size;

    vector<int> v1;
    for (int i=0; i<vec_size; i++){
        int n=0;
        cin >> n;
        v1.push_back(n);
    }

    int a_op, b_op;
    cin >> a_op;
    cin >> b_op;


    v1.erase(begin(v1) + a_op);

    v1.erase(remove(begin(v1), end(v1), b_op), v1.end());

    cout << v1.size() << endl;

    for (auto i=0; i < v1.size(); ++i){
        cout << v1[i] << " ";
    }

    return 0;
}