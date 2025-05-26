#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <string>
#include <memory>
#include <utility>
#include <map>

using namespace std;

void dynamic_alloc(){
    int length;
    char* name= new char[length+1]; // new 로 할당
    delete [] name; // delete 로 해제
    return;
}

void smart_pointer(){
    unique_ptr<int> pu1 {new int(3)};
    auto pu2 = make_unique<int>(3);
    
    int* pint = pu1.get();
    auto pustr = make_unique<string> ("fuck mathematics");
    pustr.reset(new string());
    unique_ptr<int[]> puarr {new int[3]};
    for (int i=0;i<3;i++) puarr[i] = i+2;

    unique_ptr<int>pu3{move(pu2)};
    auto pu4 = move(pu3);

    return;
}

void banned_ptr(){
    int b;
    unique_ptr<int> pub{&b}; 
    // unique_ptr 는 자동 delete 설정 되는데 
    //new로 생성한 객체가 아니면 정의되지 않은 동작 발생

    unique_ptr<int> pui {new int(3)};
    unique_ptr<int> pui2{pui}; //이렇게 되면 이중삭제가 발생힘
    pui2 = pui; // 마찬가지로 복사도 안됨
}

void shared_poniter(void){
    shared_ptr<int> ps1{new int(3)};
    shared_ptr<int> ps2{ps1};
    auto ps3 = make_shared<int>(4);
    shared_ptr<int> ps4{ps3};
}

void const_pointer(const char* str){ // 상수에 대한 포인터
    int count = 0;
    cout << str << endl;

    const int* cInt = & count; // 다른 주소를 가리키는건 가능, *cInt 로 값 변경은 불가

    int intV1 = 200;
    int intV2 = 100;
    
    int* pIntV = &intV2;
    pIntV = &intV1; // 다른 변수를 가리킨다.

    int* const cpIntV = &intV2; // *cpIntV로 값변경은 가능
    cpIntV = &intV1; // 상수 포인터는 초기화 이후 다른 주소 대입 불가
}

// 포인터 대신 참조변수를 쓰자 !
void reference_val(void){
    int ia = 10;
    int& ria = ia; // ria 값 변경 시 ia 도 변경, ia 변경시 ria도 변경
    // 참조변수는 기존의 변수를 가리키도록 초기화. 이후 다른 변수 가리킬 수 없다.
}

void dyanamic_2d_array(void){
    int row = 3, col = 3;
    int** const intArr1 = new int*[row];
    for(int i=0; i<row; ++i){
        intArr1[i]= new int[col];
        for(int j;j<col;++j) {
            cout << "입력: " << endl;
            cin >> intArr1[i][j];
        }
    }

    for(int i=0; i< row;++i){
        delete [] intArr1[i];
    }
    delete[] intArr1;
}

void type_struct(){
    enum School{
        Trinity = 0,
        Millenium = 1,
        Gehenna = 2
    };

    struct Student {
        string name;
        School school;
        int grade;
    };

    Student Hayase = {"Yuuka", Millenium, 2 };
    Student* Ushio = new Student;

    *Ushio = Hayase;
    Ushio->name = "Noah";

    cout << Hayase.name << endl;
    cout << Ushio->grade << endl;    

    delete Ushio; // new로 생성한 것은 delete 해야함.

    // 공용체 (union) 사용은 자제 : 동일 메모리를 사용하므로 각 필드값이 영향을 미치게 됨
    union Numeric{
        int iv;
        double dv;
    };
    Numeric values;
    values.dv = 3.14F;
    values.iv = 10;

    typedef unsigned int Age;
    using Age = unsigned int; // 둘은 같은 기능
    Age me = 24;
}

void container(){
    vector<int> vec1;
    vector<int> vec2(vec1);
    vector<int> vec3 {1,2,3};

    vec1.clear();
    cout << vec1.empty() << vec2.size() << endl;
    vec1 = vec3;
    vec1 = move(vec2);
    vec1 = {0,1,2,3,4,5};

    cout << vec1.front() << vec1.back() << vec1.data() << endl;

    vec1.insert(vec1.begin(), 10);
    cout << vec1.at(3) << endl;
    vec1.emplace_back(7);
    vec1.push_back(4);
    vec1.erase(vec1.end());
    vec1.pop_back();

    string str1;
    int intStr = stoi(str1);
    string str2 = to_string(intStr);
    string str3 = "Please give me Nintendo Switch 2"s;
    auto it1 = str1.find("Nintendo");
    auto it2 = str1.rfind("e");

    pair<string,int> pair1 {"Rikuhachima", 2};
    cout << pair1.first << ", " << pair1.second << endl;
    auto pair2 = make_pair("Kuda", 2);
    auto pair3 = std::pair{"Onikata", 3}; // c++14 이하 불가능

    map<string, int> map1 = {{"Asagi", 2}, {"Kurodate", 3}};
    map1.insert({"Saiba1",1});
    auto result = map1.insert({"saiba2",1});

    result = map1.insert_or_assign("Tendo", 1); // C++17
}