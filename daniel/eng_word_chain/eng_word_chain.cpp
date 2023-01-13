#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<string> spit;
    int number = 1;
    int turn = 1;

    for(auto i: words) {
        if (spit.size() == 0) {
            spit.push_back(i);
        } else if (spit.back()[spit.back().length()-1] != i[0] || count(spit.begin(), spit.end(), i) > 0) {
            return {number, turn};
            break;
        } else {
            spit.push_back(i);
        }
        
        if (number % n == 0) {
            number = 1;
            turn++;
        } else {
            number++;
        }
    }

    return {0, 0};
}