#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 재귀함수
void binary_transform(string s, vector<int>* process) {
    (*process)[0]++; // 함수 호출시, 함수 호출한 횟수 증가
    string filter = "";
    for(auto i:s) {
        if (i == '1') {
            filter += "1"; // '1'이 발견된 경우 필터링
        } else {
            (*process)[1]++; // '0' 개수 증가
        }
    }

    string transfered_string = "";
    int len = filter.length(); //필터링된 string의 길이
    while (len != 0) {
        transfered_string = to_string(len % 2) + transfered_string; // 필터링된 길이를 2진수로 변환
        len /= 2;
    }
    
    if (transfered_string.length() > 1) // 변환된 2진수의 길이가 1이 넘어가는 경우 재귀함수 호출로 이진변환 재개
        binary_transform(transfered_string, process);
}


vector<int> solution(string s) {
    vector<int> answer = {0,0};
    binary_transform(s, &answer);
    
    return answer;
}