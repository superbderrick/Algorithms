using System;
using System.Collections.Generic;


public class Solution {
 public static int[] solution(string s)
        {
            string numberOne = "1";
            string numberZero = '0';
            int[] answer = new int[2];

            while (s != numberOne)
            {
                answer[0] += 1;
                int oldLength = s.Length;
                int temp = s.ToList().RemoveAll(x => x == numberZero);
                answer[1] += temp;
                s = Convert.ToString(oldLength - temp, 2);
            }

            return answer;
        }
}