#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int elements_size = elements.size();
    map<int,int> answer_map;

    for (int i=0; i<=elements_size; i++) {
        for (int j=0; j<elements_size; j++) {
            answer_map[accumulate(elements.begin(), elements.begin()+i, i==0?elements[0]:0)];
            rotate(elements.begin(), elements.begin()+1, elements.end());
        }
    }

    answer = answer_map.size();

    return answer;
}