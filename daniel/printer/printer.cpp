#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int,int>> priority_pair;
    vector<pair<int,int>> sorted_priority_pair;

    for (int i=0; i<priorities.size(); i++)
        priority_pair.push_back({priorities[i], i});
    
    while(!priority_pair.empty()) {
        bool large_value_found = false;
        for (int j=1; j<priority_pair.size(); j++)
            if (priority_pair[0].first < priority_pair[j].first) { large_value_found = true; break; }

        if (large_value_found) {
            rotate(priority_pair.begin(), priority_pair.begin()+1, priority_pair.end());
        } else {
            sorted_priority_pair.push_back(priority_pair[0]);
            priority_pair.erase(priority_pair.begin());
        }
    }
    
    for (int i=0; i<sorted_priority_pair.size(); i++)
        if (sorted_priority_pair[i].second == location) { answer = i+1; break; }

    return answer;
}