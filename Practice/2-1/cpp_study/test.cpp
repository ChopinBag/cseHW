#include <iostream>

using namespace std;

int main(){
    int num = 0;
    cin >> num;
    int *arr = new int[num][99];

    for (int i=0; i < num; i++){
        cin >> arr[i];
    }

    int input_i = 0;
    cin >> input_i;

    cout << arr[arr[input_i]] << endl;

    delete arr;
    return 0;
}