#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> ret;
    
    for (auto i : s) {
        if (ret.empty())
            ret.push(i);
        else if (ret.top() == i)
            ret.pop();
        else
            ret.push(i);
    }

    answer = ret.size() > 0 ? 0 : 1;

    return answer;
}