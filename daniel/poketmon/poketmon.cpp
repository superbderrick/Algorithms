#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> sorted_list(nums.begin(), nums.end());
    
    answer = min(nums.size() / 2, sorted_list.size());

    return answer;
}