#include <iostream>
#include<vector>
#include<algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    
    answer = inner_product(A.begin(), A.end(), B.begin(), 0);

    return answer;
}