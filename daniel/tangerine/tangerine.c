#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(void* first, void* second)
{
    if (*(int*)first > *(int*)second)
        return -1;
    else if (*(int*)first < *(int*)second)
        return 1;
    else
        return 0;
}

// tangerine_len은 배열 tangerine의 길이입니다.
int solution(int k, int tangerine[], size_t tangerine_len) {
    int answer = 0;
    int num_of_size_list[10000001] = {0,};

    //tangerine크기별 개수 계산
    for (int i=0; i<tangerine_len; i++)
    {
        int index = tangerine[i]-1;
        num_of_size_list[tangerine[i]-1]++;
    }

    // tangerine 크기별 개수를 내림차순으로 정렬
    qsort(num_of_size_list, sizeof(num_of_size_list)/sizeof(int), sizeof(int), compare);

    // tagerine의 크기별 최소값 계산
    for (int i=0; i<tangerine_len; i++)
    {
        k-=num_of_size_list[i];
        answer++;

        if (k <= 0)
            break;
    }

    return answer;
}
