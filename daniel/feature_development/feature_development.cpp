#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int max = 0;

    for (int i=0; i<progresses.size(); i++) {
        int days = (100-progresses[i])/speeds[i] + (((100-progresses[i])%speeds[i])>0);
        if (answer.empty() || max < days) {
            answer.push_back(1);
            max = days;
        } else {
            answer.back()++;
        }
    }

    return answer;
}