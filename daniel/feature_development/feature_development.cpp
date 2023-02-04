#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> required_days;
    
    for (int i=0; i<progresses.size(); i++) {
        int rest = 100-progresses[i];
        required_days.push_back(rest/speeds[i] + ((rest%speeds[i])>0?1:0));
    }

    int count = 1;
    int max = required_days[0];
    for (int i=1; i<required_days.size(); i++) {
        if (max < required_days[i]) {
            answer.push_back(count);
            max = required_days[i];
            count = 1;
        } else {
            count++;
        }
    }
    answer.push_back(count);

    return answer;
}