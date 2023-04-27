#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<vector<int>> get_dfs_order(int n) {
    vector<vector<int>> ret;
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    
    do {
        ret.push_back(v);
    } while (next_permutation(v.begin(),v.end()));
    
    return ret;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<vector<int>> index_order = get_dfs_order(dungeons.size());
    
    for(auto i: index_order) {
        int count = 0;
        int exhation = k;
        for(auto j: i) {
            if (exhation >= dungeons[j][0]) {
                exhation -= dungeons[j][1];
                count++;
            }
            answer = max(answer,count);
        }
    }
    
    return answer;
}