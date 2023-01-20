using System;
using System.Collections.Generic;


public class Solution {
    public bool solution(string s) {

            bool answer = true;
            char[] testArray = s.ToCharArray();
            Stack<char> tempStack = new Stack<char>();
            int tempValue = 0;

            if (s[0].Equals(')')) 
                return false;
            
            foreach (var VARIABLE in testArray)
            {
                if (VARIABLE.Equals('('))
                {
                    //tempStack.Push(VARIABLE);
                   // tempValue++;
                    
                } else if (VARIABLE.Equals(')'))
                {
//                     if (tempStack.Count > 0)
//                     {
                        
//                         //tempStack.Pop();
//                     }   
                    //if(tempValue > 0)
                      //  tempValue--;
                }
            }
            
        if(tempValue > 0) {
            answer = false;
        } else {
            answer = true;
        }
            // if (tempStack.Count > 0)
            // {
            //     answer = false;
            // }
            // else
            // {
            //     answer = true;
            // }
            
            return answer;
    }
}