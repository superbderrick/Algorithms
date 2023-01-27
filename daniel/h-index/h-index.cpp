#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<int>());
    int n = citations.size();
    for (int i=1; i<=n; i++) {
        int h = 0;
        for (int j=1; j<=n; j++) {
            if (citations[j-1] >= citations[i-1]) h++;
        }
        if (citations[i-1] >=h && n-i <=h)
            answer = h;
    }
    return answer;
}