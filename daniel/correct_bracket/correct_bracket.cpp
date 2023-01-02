#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pair = 0;

    for (auto i:s) {
        if (pair == 0 && i == ')')
            return false;
            
        if (i == '(')
            pair++;
        else
            pair--;

    }
    answer = (pair == 0);

    return answer;
}