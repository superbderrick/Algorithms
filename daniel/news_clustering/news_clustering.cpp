#include <string>
#include <map>
#include <cctype>
#include <iostream>

using namespace std;

map<string,int> get_string_map(string input, int* num_of_map) {
    map<string,int> ret;

    for (int i=0; i<input.size()-1; i++) {
        if (isalpha(input[i]) && isalpha(input[i+1])) {
            string key = {(char)toupper(input[i]), (char)toupper(input[i+1])};
            ret[key]++;
            (*num_of_map)++;
        }
    }

    return ret;
}

int solution(string str1, string str2) {
    int answer = 0;

    int intersection_ = 0;
    int union_ = 0;

    int num_of_map_str1 = 0;
    int num_of_map_str2 = 0;
    map<string,int> map_str1 = get_string_map(str1, &num_of_map_str1);
    map<string,int> map_str2 = get_string_map(str2, &num_of_map_str2);
   
    for (auto i:map_str1)
        intersection_ += min(i.second, map_str2[i.first]);

    // A ∪ B = A + B - A ∩ B
    union_ = num_of_map_str1 + num_of_map_str2 - intersection_;

    answer = union_ > 0 ? (intersection_* 65536/union_) : 65536;

    return answer;
}