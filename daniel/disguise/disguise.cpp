#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> clothes_map;

    // 옷을 종류별 개수로 mapping.
    for (auto cloth: clothes) {
        clothes_map[cloth[1]] += 1;
    }
    
    /* 옷을 입지 않는 경우를 고려하여 옷의 종류별 개수 + 1 처리.
     * ex) 예제 #1의 경우, clothes_map["headgear"] = 3; //"yellow_hat", "green_turban", "naked"
     * 옷의 종류별 개수 만큼 곱하여 조합 계산.
    */
    for (auto pair: clothes_map) {
        answer *= (pair.second + 1);
    }
    
    // 모든 옷을 입지 않는 경우의 수 계산.
    answer -= 1;

    return answer;
}