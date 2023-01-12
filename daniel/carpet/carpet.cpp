#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int i=1; i<=yellow; i++) {
        if (yellow % i == 0) {
            int x = yellow / i;
            int y = i;
            if (2*(x+y+2) == brown) {
                answer.push_back(x+2);
                answer.push_back(y+2);
                break;
            }
        }
    }
    
    return answer;
}