#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int cycle = (left)/n + 1;
    long long target = 0;
    for(long long i=left+1; i<=right+1; i++) {
        if (i%n == 0) { cycle++; target = n; }
        else { target = i%n<=cycle ? cycle : i%n; }

        answer.push_back(target);
    }

    return answer;
}