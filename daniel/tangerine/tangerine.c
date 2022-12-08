#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void sort(int* array, int len);

// tangerine_len은 배열 tangerine의 길이입니다.
int solution(int k, int tangerine[], size_t tangerine_len) {
    int answer = 0;
    int *size_list = (int*)malloc(sizeof(int)*tangerine_len);
    int *num_of_size_list = (int*)malloc(sizeof(int)*tangerine_len);
    
    memset(size_list, 0, sizeof(int)*tangerine_len);
    memset(num_of_size_list, 0, sizeof(int)*tangerine_len);

    //tangerine 크기 종류와 tangerine크기별 개수 계산
    for (int i=0; i<tangerine_len; i++)
    {
        for (int j=0; i<tangerine_len; j++)
        {
            if(size_list[j] == 0)
            {
                size_list[j] = tangerine[i];
                num_of_size_list[j]++;
                break;
            }
            else if(size_list[j] == tangerine[i])
            {
                num_of_size_list[j]++;
                break;
            }
        }
    }

    // tangerine 크기별 개수를 내림차순으로 정렬
    sort(num_of_size_list, tangerine_len);

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

void sort(int* array, int len)
{
    for (int i=0; i<len; i++)
    {
        if (array[i] == 0)
            break;
        for (int j=i; j<len; j++)
        {
            if (array[j] > array[i])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    
}