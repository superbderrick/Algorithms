
using System.Collections.Generic;
using System;

public class Solution {
    public int solution(int n) {
        int answer = 0;
        int temp = 0;
        const int sampleNumber = 1234567;
        
        List<int> fibonachiList = new List<int>();

        if(n >1) {
            for(int i = 0 ; i< 100001 ; i++) {
            if(i == 0) {
                fibonachiList.Add(0);    
            } else if(i == 1) {
                fibonachiList.Add(1);    
            } else {
                temp = fibonachiList[i-1] % sampleNumber + fibonachiList[i-2] % sampleNumber;
                fibonachiList.Add(temp);    
            }
         }
           
          answer = fibonachiList[n] % sampleNumber;
              
        } 
        
        // (A + B) % C ≡ ( ( A % C ) + ( B % C) ) % C Goot tips

        return answer;
    }
}