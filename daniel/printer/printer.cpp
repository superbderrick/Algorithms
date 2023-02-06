#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> priorities_index;
    vector<int> sorted_priorities_index;

    for (int i=0; i<priorities.size(); i++) priorities_index.push(i);
    
    while(!priorities_index.empty()) {
        int target_index = priorities_index.front();
        if (priorities[target_index] != *max_element(priorities.begin(), priorities.end())) {
            priorities_index.push(target_index);
        } else {
            sorted_priorities_index.push_back(target_index);
            priorities[target_index] = -1;
        }
        priorities_index.pop();
    }
    
    for (int i=0; i<sorted_priorities_index.size(); i++)
        if (sorted_priorities_index[i] == location) { answer = i+1; break; }

    return answer;
}