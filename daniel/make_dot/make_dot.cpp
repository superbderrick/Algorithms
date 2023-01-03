#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(int k, int d) {
    long long answer = 0;
    int x = 0;
    int y = 0;

    if ((1<=k && k<=1000000) && (1<=d && d<=1000000))
    {
        for(x=0; x*k<=d; x++)
        {
            if (x*k <= d)
            {
                y = (int)sqrt(pow(d,2)-pow(x*k,2));
                answer = answer + 1 + y/k;
            }
        }
    }

    return answer;
}