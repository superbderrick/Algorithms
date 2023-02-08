#include <string>
#include <vector>

using namespace std;

void get_answer(vector<int> numbers, int target, int* count) {  
    if (numbers.size() == 1) {
        if (numbers[0] == target) (*count)++;
    } else {
        int numbers_begin_plus, numbers_begin_minus;
        numbers_begin_plus = numbers_begin_minus = numbers[0];
        numbers.erase(numbers.begin());

        numbers_begin_plus += numbers[0];
        numbers_begin_minus -= numbers[0];

        numbers[0] = numbers_begin_plus;
        get_answer(numbers, target, count);

        numbers[0] = numbers_begin_minus;
        get_answer(numbers, target, count);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    get_answer(numbers, target, &answer);
    numbers[0] = -numbers[0];
    get_answer(numbers, target, &answer);
    
    return answer;
}