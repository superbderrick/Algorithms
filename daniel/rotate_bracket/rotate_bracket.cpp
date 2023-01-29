#include <string>
#include <vector>

using namespace std;
int check_string(string s) {
    vector<char> stack;
    
    for (auto c : s) {
        if (stack.empty()) {
            stack.push_back(c);
        } else {
            switch (c) {
                case ')' : if (stack.back() == '(') stack.pop_back(); break;
                case '}' : if (stack.back() == '{') stack.pop_back(); break;
                case ']' : if (stack.back() == '[') stack.pop_back(); break;
                default : stack.push_back(c); break;
            }
        }
    }
    
    return stack.size();
}

int solution(string s) {
    int answer = 0;
    
    for (int i=0; i<s.size(); i++) {
        if (check_string(s) == 0) answer++;
        s.push_back(s.front());
        s.erase(s.begin());
    }
    
    return answer;
}