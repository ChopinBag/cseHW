#ifndef STRINGSPLITTER_H
#define STRINGSPLITTER_H

#include <string>
#include <vector>

class StringSplitter {
private:
    std::string str; // 처리할 문자열 저장

public:
    // 생성자: 입력 문자열 초기화
    StringSplitter(const std::string& input);
    
    // 문자열 앞뒤 공백 제거
    StringSplitter& trim();
    
    // 부분 문자열 교체
    StringSplitter& replaceSubstring(const std::string& oldStr, const std::string& newStr);
    
    // 구두점 제거
    StringSplitter& removePunctuation();
    
    // 문자열을 구분자로 분리하여 토큰 배열 반환
    std::vector<std::string> split(char delimiter);
};

#endif // STRINGSPLITTER_H
