#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if (cacheSize == 0)
        return 5*cities.size();

    vector<string> cache;
    for(auto city : cities) {
        boost::algorithm::to_lower(city);
        auto index = find(cache.begin(), cache.end(), city);

        if (index != cache.end()) {
            answer += 1;
        } else {
            index = cache.begin();
            answer += 5;
        }

        if (cache.size() == cacheSize)
            cache.erase(index);
        cache.push_back(city);
    }
    return answer;
}