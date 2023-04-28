#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dictionary;
    for (int i=0; i<26; i++) {
        dictionary[string(1, 'A'+i)] = i+1;
    }
    
    string w = "";
    for (int i=0; i<msg.size(); i++) {
        w += msg[i];
        string c = msg[i+1] ? string(1,msg[i+1]) : "";
        if (c == "") {
            answer.push_back(dictionary[w]);
        } else {
            if (dictionary.find(w+c) == dictionary.end()) {
                dictionary[w+c] = dictionary.size()+1;
                answer.push_back(dictionary[w]);
                w.clear();
            }
        }
    }
    
    return answer;
}