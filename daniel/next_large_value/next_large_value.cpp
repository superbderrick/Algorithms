#include <string>
#include <vector>

using namespace std;

int get_num_of_one(int n) {
    int ret = 1;
    while(n > 1) {
        if (n%2 == 1) ret++;
        n /= 2;
    }
    
    return ret;
}

int solution(int n) {
    int answer = 0;
    int num_of_one = get_num_of_one(n++);

    while(1) {
        if (num_of_one == get_num_of_one(n))
            break;
        n++;
    }

    answer = n;

    return answer;
}