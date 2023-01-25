#include <string>
#include <vector>

using namespace std;

long long get_fibonacci_div(int prev, int cur, int index, int max) {
    long long ret = (prev%1234567 + cur%1234567)%1234567;
    if (max > index)
        ret = get_fibonacci_div(cur, ret, index+1, max);
    return ret;
}

long long solution(int n) {
    long long answer = n <= 3 ? n : get_fibonacci_div(2, 3, 4, n);

    return answer;
}