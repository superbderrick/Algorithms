#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int>b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    string value = "";
    vector<vector<int>> tuples;
    vector<int> tuple;
    for(auto c : s) {
        switch(c) {
            case '}': if (value.size()>0) {tuple.push_back(stoi(value)); tuples.push_back(tuple); tuple.clear(); value.clear();} break;
            case ',': if (value.size()>0) {tuple.push_back(stoi(value)); value.clear();} break;
            default : if (isdigit(c)) value += c; break;
        }
        
    }

    sort(tuples.begin(), tuples.end(), cmp);

    for (auto tuple: tuples) {
        for (auto i: tuple) {
            if (find(answer.begin(), answer.end(), i) == answer.end()) {
                answer.push_back(i);
            }
        }
    }

    return answer;
}