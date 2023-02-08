#include <string>
#include <vector>

using namespace std;

void get_answer(vector<int> &numbers, int &target, int sum, int index, int* count) {
    if(index == numbers.size()){
        if(sum == target) (*count)++;
        return;
    }

    get_answer(numbers, target, sum + numbers[index], index+1, count);
    get_answer(numbers, target, sum - numbers[index], index+1, count);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    get_answer(numbers, target, numbers[0] , 1, &answer);
    get_answer(numbers, target, -numbers[0], 1, &answer);

    return answer;
}