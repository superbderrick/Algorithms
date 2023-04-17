#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> want_map;
    
    for(int i=0; i<want.size(); i++) {
        want_map[want[i]] = number[i];
    }
    
    for(int i=0; i<discount.size(); i++) {
        map<string, int> discount_map;
        bool should_count = true;
        for(int j=0; j<10; j++) {
            if (i+j == discount.size())
                break;
            discount_map[discount[i+j]]++;
        }
        
        for (auto item: want_map) {
            should_count &= discount_map[item.first] == want_map[item.first];
        }
        
        if (should_count)
            answer++;
    }
    
    return answer;
}