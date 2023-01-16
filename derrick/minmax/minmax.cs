using System;
using System.Collections.Generic;

namespace Chapter03
{
    class Program
    {
        static void Main(string[] args)
        {

            string s = "-1 -2 -3 -4";
            Console.Write(solution(s));
          //  solution(s);
        }

        public static string solution(string s)
        {
            string[] tokens = s.Split(' ');
            int[] convertedItems = Array.ConvertAll<string, int>(tokens, int.Parse);
            
            int min  = 0;
            int max  = 0;
            

            for (int i = 0; i < convertedItems.Length ; i++)
            {
                if (i == 0)
                {
                    min = convertedItems[i];
                    max = convertedItems[i];
                }
                else
                {
                    if (max<convertedItems[i])
                    {
                        max = convertedItems[i];
                    } else if (min>convertedItems[i])
                    {
                        min = convertedItems[i];
                    }
                    
                }
                
            }
            
            string answer = min.ToString() + " "+max.ToString();
            
            
            return answer;
        }
    }
}

// Good case
// string answer = "";
//         int[] temp = s.Split(' ').Select(int.Parse).ToArray();
//         answer = temp.Min().ToString() + " " +temp.Max().ToString();
//         return answer;