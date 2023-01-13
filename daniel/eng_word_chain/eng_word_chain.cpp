#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    map<string, bool> spit;

    spit[words[0]] = true;
    for(int i=1; i<words.size(); i++) {
        if (spit[words[i]] == true || words[i-1][words[i-1].length()-1] != words[i][0]) {
            return {(i%n)+1, (i/n)+1};
        } else {
            spit[words[i]] = true;
        }
    }

    return {0, 0};
}