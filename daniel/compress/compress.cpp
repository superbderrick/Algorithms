#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> search_map;
    for (int i=0; i<26; i++) {
        char temp_char = 'A'+i;
        string temp_string;
        temp_string += temp_char;
        search_map[temp_string] = i+1;
    }

    string w = "";
    for (int i=0; i<msg.size(); i++) {
        string c = "";      
        if (msg[i+1]) c += msg[i+1];
        w += msg[i];

        if (c == "") {
            answer.push_back(search_map[w]);
        } else {
            if (search_map.find(w+c) == search_map.end()) {
                search_map[w+c] = search_map.size()+1;
                answer.push_back(search_map[w]);
                w.clear();
            }
        }
    }

    return answer;
}