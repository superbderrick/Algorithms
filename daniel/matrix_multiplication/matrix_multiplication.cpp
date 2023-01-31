#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<vector<int>> transformed_arr2;
    
    for (int i=0; i<arr2[0].size(); i++) {
        vector<int> temp;
        for (int j=0; j<arr2.size(); j++) {
            temp.push_back(arr2[j][i]);
        }
        transformed_arr2.push_back(temp);
    }
    
    for (int i=0; i<arr1.size(); i++) {
        vector<int> temp;
        for (int j=0; j<transformed_arr2.size(); j++) {
            int ip = inner_product(arr1[i].begin(), arr1[i].end(), transformed_arr2[j].begin(), 0);
            temp.push_back(ip);
        }
        answer.push_back(temp);
    }
    
    return answer;
}