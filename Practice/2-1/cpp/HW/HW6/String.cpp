#include "String.h"
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int String::count_ = 0;

String::String()
  : len_{0}, data_{new char[1]{'\0'}}
{
    cout << "Default Constructor\n";
    ++count_;
    cout << "# of String object: " << count_ << "\n";
}

String::String(const char* s)
  : len_{strlen(s)}, data_{new char[len_ + 1]}
{
    copy(s, s + len_ + 1, data_);
    cout << "Constructor\n";
    ++count_;
    cout << "# of String object: " << count_ << "\n";
}

String::~String() noexcept
{
    cout << "Destructor\n";
    --count_;
    cout << "# of String object: " << count_ << "\n";
    delete[] data_;
}

String::String(const String& s) noexcept
  : len_{s.len_}, data_{new char[len_ + 1]}
{
    copy(s.data_, s.data_ + len_ + 1, data_);
    cout << "Copy Constructor\n";
    ++count_;
    cout << "# of String object: " << count_ << "\n";
}

const char* String::data() const {
    return data_;
}

bool String::empty() const {
    return len_ == 0;
}

size_t String::size() const {
    return len_;
}

String& String::append(const String& str) {
    size_t new_len = len_ + str.len_;
    char* new_data = new char[new_len + 1];
    copy(data_, data_ + len_, new_data);
    copy(str.data_, str.data_ + str.len_ + 1, new_data + len_);
    delete[] data_;
    data_ = new_data;
    len_ = new_len;
    return *this;
}

String& String::append(const char* s) {
    size_t add = strlen(s);
    size_t new_len = len_ + add;
    char* new_data = new char[new_len + 1];
    copy(data_, data_ + len_, new_data);
    copy(s, s + add + 1, new_data + len_);
    delete[] data_;
    data_ = new_data;
    len_ = new_len;
    return *this;
}