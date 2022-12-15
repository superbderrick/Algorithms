#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(void* first, void* second)
{
    if(*(int*)first > *(int*)second)
        return 1;
    else if(*(int*)first < *(int*)second)
        return -1;
    return 0;
}

int is_depense_ok(int n, int k, int mid, int* enemy)
{
    // 적 병사를 내림차순 정렬.
    int *sorted_enemy = (int*)malloc(sizeof(int)*(mid+1));
    memcpy(sorted_enemy, enemy, sizeof(int)*(mid+1));
    qsort(sorted_enemy, mid+1, sizeof(int), compare);
    
    int remain = mid+1;
    int ret = 0;
    
    for (int i=0; i<=mid; i++)
    {
        if (n>=sorted_enemy[i])
        {
            n-= sorted_enemy[i];
            remain--;
            continue;
        }
        
        
        
    }
    free(sorted_enemy);
    
    // 남은 병사 숫자로 성공(1), 실패(0) 리턴
    return k >= remain;
}

// enemy_len은 배열 enemy의 길이입니다.
int solution(int n, int k, int enemy[], size_t enemy_len) {
    int answer = 0;
    
    int ret = 0;
    int begin = 0;
    int end = enemy_len;
    int mid = 0;
    
    // 2진 search로 성공가능한 round 탐색
    while (begin < end)
    {
        mid = (begin + end) / 2;
        
        // 성공 가능한지 여부를 체크하여 2진트리 인덱스 재설정
        if (is_depense_ok(n, k, mid, enemy))
        {
            begin = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    if (k>=enemy_len) // 무적권만으로 전체 라운드를 클리어할 경우
        answer = enemy_len;
    else // 성공했던 round 리턴
        answer = begin;

    return answer;
}

