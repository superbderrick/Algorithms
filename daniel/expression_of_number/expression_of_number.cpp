#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum = 0;
    int j = 1;

    for (int i = j; i<=n; i++) {
        sum+=i;
        if (sum >= n) {
            if (sum == n) answer++;
            i = j++;
            sum = 0;
        }
    }

    return answer;
}