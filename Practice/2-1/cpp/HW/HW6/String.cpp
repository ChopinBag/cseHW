#include "String.h"
#include <cstring> 
#include <iostream>
#include <algorithm>

//Implement your code

using namespace std;

int String::count_ = 0; // static 변수 초기화

String::String() { // 기본 생성자
    len_ = 0;
    data_ = new char[len_ +1]; // 끝에 null 문자 담기 위해 동적 할당 필요
    // data_ = new char[1];
    data_[0] = '\0';
    count_++;
    // 문제 요구사항에 맞게 cout
}

String::String(const char* s){
    len_ = strlen(s);
    data_ = new char[len_+1];
    copy(s, s+len_+1, data_);
};

String::~String() noexcept{ // 소멸자 공통 사용
    delete[] data_;
    count_--;
};


String::String(const String& s) noexcept{  //복사 생성자
    this->len_ = s.len_;
    this->data_ = new char[len_+1];
    // deep copy
    if(s.data_[0] == '\0'){
        this->data_[0] = '\0';
        return;
    }
    strcpy(this->data_, s.data_);
};

const char* String::data() const{
    return data_;
};

bool String::empty() const{
    return len_ == 0;
};

size_t String::size() const{
    return len_;
};

String& String::append(const String& str){};

String& String::append(const char* str){};