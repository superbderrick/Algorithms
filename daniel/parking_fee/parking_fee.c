#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int compare(void* first, void* second) {
    return ( *(int*)first > *(int*)second);
}

int found_car_number(int* car_numbers, size_t car_numbers_size, int number_to_find) {
    for (int j=0; j<car_numbers_size; j++) {
        if (car_numbers[j] == number_to_find)
            return 1;
    }
    
    return 0;
}

// fees_len은 배열 fees의 길이입니다.
// records_len은 배열 records의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer;
    
    int* car_numbers;
    size_t car_numbers_length = 1;
    car_numbers = (int*)malloc(car_numbers_length * sizeof(int));

    // variables for parsing records.
    int hours, mins, car_num;
    char status[4];
    
    // Get car_number's list
    for (int i=0; i<records_len; i++) {
        sscanf(records[i], "%d:%d %d %s", &hours, &mins, &car_num, status);
        if (i==0) {
            car_numbers[0] = car_num;
        } else if (!found_car_number(car_numbers, car_numbers_length, car_num)) {
            car_numbers = (int*)realloc(car_numbers, (++car_numbers_length)*sizeof(int));
            car_numbers[car_numbers_length-1] = car_num;
        }
    }
    
    // Sort car_numbers.
    qsort(car_numbers, car_numbers_length, sizeof(int), compare);
    
    // Allocate answer memory by car_number's length
    answer = (int*)malloc(car_numbers_length*sizeof(int));
    memset(answer, 0, car_numbers_length*sizeof(int));

    // Check car_numbers each
    for (int j=0; j<car_numbers_length; j++) {
        int begin_time = 0, elapsed_time = 0;
        int paired = 0;
        // Parse records
        for (int i=0; i<records_len; i++) {
            sscanf(records[i], "%d:%d %d %s", &hours, &mins, &car_num, status);
            if (car_numbers[j] == car_num) {
                // Set begin_time when status is "IN"
                if (strncmp(status, "IN", 3) == 0) {
                    begin_time = hours*60 + mins;
                    paired = 0;
                }
                // Set elapsed_time when status is "OUT"
                if (strncmp(status, "OUT", 4) == 0) {
                    elapsed_time += (hours*60 + mins) - begin_time;
                    paired = 1;
                }
            }
        }

        // Set elapsed_time when there's no "OUT" status.
        if (!paired) {
            elapsed_time += (23*60 + 59) - begin_time;
        }
        
        // Get unit_time by elapsed_time.
        int unit_time = ceil((elapsed_time - fees[0]) / (double)fees[2]);

        // Get total fee and set answer.
        answer[j] += fees[1] + (unit_time > 0 ? unit_time : 0) * fees[3];
    }
    
    // Free memory.
    free(car_numbers);
    
    return answer;
}