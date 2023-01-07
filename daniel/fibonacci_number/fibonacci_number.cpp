#include <string>
#include <vector>
#include <iostream>

using namespace std;
int fibo (int first, int second, int i, int n) {
    // (A + B) % C = {(A % C) + (B % C)} % C
    int ret = (first + second) % 1234567;

    if (i < n)
        ret = fibo(second, ret, i+1, n);
    
    return ret;
}

int solution(int n) {
    int i = 0;
    int first = 0; i++; // F(0) = 0;
    int second = 1; i++;// F(1) = 1;

    int answer = fibo(first, second, i, n);

    return answer;
}