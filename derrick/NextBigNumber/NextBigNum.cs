
using System;
using System.Text;

class Solution 
{
    //Condiotion 01 more than bigger n
    // after convert bineray it's same number 1
    // most mimerst

    public int solution(int n) 
   {
        int answer = 0;
        int oneNum = 0;

        string binN = Convert.ToString(n,2);
        StringBuilder builder = new StringBuilder(binN);


        for(int i = 0 ; i< builder.Length ; i++) {
            if(builder[i].Equals('1')) {
                oneNum++;
            }
        }

        int finalTempNum = 0;
        int nextN = n+1;

        while(oneNum != finalTempNum) {

        int finalNum = nextN;
        string finalBin = Convert.ToString(finalNum,2);

        StringBuilder tempbuilder = new StringBuilder(finalBin);
        for(int i = 0 ; i< tempbuilder.Length ; i++) {
            if(tempbuilder[i].Equals('1')) {
                finalTempNum++;

            }
        }
            if(finalTempNum == oneNum) {
                break;
            }
            nextN++;
            finalTempNum =0;

        }


        return nextN;
    }
}



//good
// using System;
// using System.Linq;

// class Solution 
// {
//     public int solution(int n) 
//     {
//         int countOfOne = Convert.ToString(n, 2).ToArray().Where(d => d == '1').Count();

//         while (true)
//         {
//             n++;

//             if (countOfOne == Convert.ToString(n, 2).ToArray().Where(d => d == '1').Count())
//                 break;
//         }

//         return n;
//     }
// }
// It didnt do well with nomal convert api and string builder and while loop than for , let see the linq prospective 