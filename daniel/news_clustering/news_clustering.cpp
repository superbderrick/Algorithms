#include <string>
#include <map>
#include <cctype>
#include <iostream>

using namespace std;

map<string,int> get_string_map(string input, int* sum) {
    map<string,int> ret;
    
    for (int i=0; i<input.size()-1; i++) {
        if (isalpha(toupper(input[i])) && isalpha(toupper(input[i+1]))) {
            string key = "";
            key+=toupper(input[i]);
            key+=toupper(input[i+1]);
            ret[key]++;
            (*sum)++;
        }
    }
    
    return ret;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    int sum1 = 0;
    int sum2 = 0;
    map<string,int> map_str1 = get_string_map(str1, &sum1);
    map<string,int> map_str2 = get_string_map(str2, &sum2);

    double union_ = sum1 + sum2;
    double intersection_ = 0;

    for (auto i:map_str1) {
       if (map_str2.find(i.first) != map_str2.end()) {
           intersection_ += min(i.second, map_str2[i.first]);
        }
    }

    double J = (union_-intersection_) > 0 ? (intersection_/(union_ - intersection_)) : 1.0;
    answer = J * 65536;

    return answer;
}