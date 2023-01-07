using System.Collections.Generic;
using System.Linq;

namespace Algorithmstudy
{
    class Program
    {
        static void Main(string[] args)
        {

            solution(6, new []{1, 3, 2, 5, 4, 5, 2, 3});
        }
        
        static int solution(int k, int[] tangerine)
        {
            
            int answer = 0;
            int count = 0;
            Dictionary<int ,int> hashSet = new Dictionary<int, int>();

            for(int i = 0 ; i < tangerine.Length ; i++)
            {
                if(!hashSet.ContainsKey(tangerine[i]))
                    hashSet.Add(tangerine[i],1);
                else
                    hashSet[tangerine[i]]++;
            }

            hashSet = hashSet.OrderByDescending(x=>x.Value).ToDictionary(x=>x.Key,x=>x.Value);
            foreach(KeyValuePair<int,int> item in hashSet)
            {
                count += item.Value;
                answer++;
                if(count >= k)
                    break;
            }

            return answer;
        }
    }
}