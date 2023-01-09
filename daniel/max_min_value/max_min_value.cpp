#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    string tmp;
    int max = 0;
    int min = 0;
    bool try_once = false;
    while(getline(ss, tmp, ' ')) {
        int val = stoi(tmp);
        if (try_once == false) {
            max = val;
            min = val;
            try_once = true;
        } else {
            if (val > max)
                max = val;
            if (val < min)
                min = val;
        }
    }
    
    answer = to_string(min) + " " + to_string(max);
    
    return answer;
}