#include "StringSplitter.h"
#include <algorithm>
#include <cctype>

// 생성자 
StringSplitter::StringSplitter(const std::string& input) : str(input) {}

// 문자열 앞뒤 공백 제거
StringSplitter& StringSplitter::trim() {
    // 앞쪽 공백 제거
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    
    // 뒤쪽 공백 제거
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), str.end());
    
    return *this; // this 포인터 참조 반환으로 메서드 체이닝 가능
}

// 부분 문자열 교체
StringSplitter& StringSplitter::replaceSubstring(const std::string& oldStr, const std::string& newStr) {
    size_t pos = 0;
    while ((pos = str.find(oldStr, pos)) != std::string::npos) {
        str.replace(pos, oldStr.length(), newStr);
        pos += newStr.length();
    }
    
    return *this; // this 포인터 참조 반환
}

// 구두점 제거
StringSplitter& StringSplitter::removePunctuation() {
    str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char ch) {
        return std::ispunct(ch);
    }), str.end());
    
    return *this; // this 포인터 참조 반환
}

// 문자열 분리
std::vector<std::string> StringSplitter::split(char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    size_t pos = 0;
    
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        if (!token.empty()) {
            tokens.push_back(token);
        }
        str.erase(0, pos + 1);
    }
    
    // 마지막 토큰 처리
    if (!str.empty()) {
        tokens.push_back(str);
    }
    
    return tokens; // 최종 결과 반환(토큰 배열)
}
