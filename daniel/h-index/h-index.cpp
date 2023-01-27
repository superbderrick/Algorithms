#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end(), greater<int>());
    int n = citations.size();
    for(int i=1; i<=n; i++) {
        if(citations[i-1] >= i)
            answer = i;
    }

    return answer;
}