#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int>b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    string value = "";
    map<int, int> tuple_map;
    for(auto c : s) {
        switch(c) {
            case '}':
            case ',': if (value.size()>0) {tuple_map[stoi(value)]++; value.clear();} break;
            default : if (isdigit(c)) value += c; break;
        }
    }

    vector<pair<int, int>> tuple_vector(tuple_map.begin(), tuple_map.end());
    sort(tuple_vector.begin(), tuple_vector.end(), cmp);
   
    for (auto i: tuple_vector) {
        answer.push_back(i.first);
    }

    return answer;
}