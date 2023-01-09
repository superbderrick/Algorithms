#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer;
    bool toggle = false;
    for (auto i: s) {
        if (i == ' ') {toggle = false;}
        else {
            if (toggle == false) {
                i = toupper(i);
                toggle = true;
            } else {
                i = tolower(i);
            }
        }
        answer += i;
    }
    return answer;
}