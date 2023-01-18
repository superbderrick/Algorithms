#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
int solution(vector<int> arr) {
    int answer = 1;
    map<int, int> ret;

    for (auto j: arr) {
        int i=2;
        map<int, int> temp;
        while (j != 1) {
            if (j%i == 0) {
                if (ret[i] < ++temp[i]) ret[i]=temp[i];
                j/=i;
            } else {
                i++;
            }
        }
    }

    for (auto i: ret) {
        answer *= pow(i.first, i.second);
    }

    return answer;
}