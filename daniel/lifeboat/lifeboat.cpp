#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

// 핵심 : 가장 무거운 사람이 가장 가벼운사람을 데리고 갈 수 있으면 데려가!
int solution(vector<int> people, int limit) {
    int answer = 0;
    int front = 0;
    int end = people.size()-1;

    sort(people.begin(), people.end());

    while(front<=end) {
        if (people[end] + people[front] <= limit) {
            front++; end--;
        } else { 
            end--;
        }
        answer++;
    }

    return answer;
}