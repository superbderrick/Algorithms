#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(void* first, void* second)
{
    if (*(int*)first < *(int*)second)
        return -1;
    else if (*(int*)first > *(int*)second)
        return 1;
    
    return 0;
}

/*
 * arrayA, arrayB의 가장 작은 숫자카드의 공약수를 비교하여 arrayA, arrayB 배열의 원소와 나누어떨어지는지 비교.
*/
int getAnswer(int* arrayA, int* arrayB, size_t array_len)
{
    int ret = 0;
    int maxIdx = 0;

    // arrayA, arrayB를 오름차순으로 정렬
    qsort(arrayA, array_len, sizeof(int), compare);
    qsort(arrayB, array_len, sizeof(int), compare);
    
    maxIdx = arrayA[0] > arrayB[0] ? arrayA[0] : arrayB[0]; // arrayA[0], arrayB[0]의 max 값으로 index 설정
    
    for (int i=maxIdx; i>=2; i--) // 1, 0으로 나누어떨어지는 경우는 고려하지 않아 i>=2
    {
        int count = 0;
        int countType = -1;
        // arrayA[0], arrayB[0]가 둘 다 나누어 떨어지지 않거나 둘 다 나누어 떨어지는 경우는 제외.
        if (arrayA[0]%i != 0 && arrayB[0]%i != 0 || arrayA[0]%i == 0 && arrayB[0]%i == 0)
            continue;

        // count 할 수 있는 경우에 따라 count 하는 방법(countType) 설정
        if (arrayA[0]%i == 0 && arrayB[0]%i != 0) // arrayA[0]가 i로 나누어 떨어지고 arrayB[0]가 i로 나누어 떨어지지 않는 경우
            countType = 1;
        else if (arrayB[0]%i == 0 && arrayA[0]%i != 0) // arrayB[0]가 i로 나누어 떨어지고 arrayA[0]가 i로 나누어 떨어지지 않는 경우
            countType = 0;
        
        for (int j=0; j<array_len; j++)
        {
            if (countType == 0)
                arrayA[j]%i !=0 && arrayB[j]%i == 0 ? count++ : count; // arrayB에서만 i로 나누어 떨어지는 원소의 개수를 count
            else
                arrayB[j]%i !=0 && arrayA[j]%i == 0 ? count++ : count; // arrayA에서만 i로 나누어 떨어지는 원소의 개수를 count
        }
        
        // 모든 원소만큼 count 했을때 나누어 떨어지는 i를 계산 후 반복문 종료.
        if (count == array_len)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

// arrayA_len은 배열 arrayA의 길이입니다.
// arrayB_len은 배열 arrayB의 길이입니다.
int solution(int arrayA[], size_t arrayA_len, int arrayB[], size_t arrayB_len) {
    int answer = getAnswer(arrayA, arrayB, arrayA_len);

    return answer;
}