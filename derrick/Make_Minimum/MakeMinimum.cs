        static void Main(string[] args)
        {
           int[] testArrayA = {6, 5, 2,6,7,8};
           int[] testArrayB = {5, 4, 4,2,9,10};
           solution(testArrayA, testArrayB);

        }

        public static int solution(int[] A, int[] B) {
            int answer = 0;
            int tempA = 0;
            int tempB = 0;
            int result = 0;

            
            for(int i = 0; i < A.Length-1; i++)
            {
                for (int j = 0; j < A.Length-1; j++)
                {
                    if(A[j] > A[j+1])  
                    {
                        tempA = A[j+1];
                        A[j+1] = A[j];
                        A[j] = tempA;
                    }
                }
            }
            
            for(int i = 0; i < B.Length-1; i++)
            {
                for (int j = 0; j < B.Length-1; j++)
                {
                    if(B[j] < B[j+1])  
                    {
                        tempB = B[j+1];
                        B[j+1] = B[j];
                        B[j] = tempB;
                    }
                }
            }

            

            for (int k = 0; k < A.Length ; k++)
            {
                result += A[k] * B[k];
            }
            
            
            
            return result;
        }

        //Good Case





// public class Solution {
//     public int solution(int[] A, int[] B) {
//         int answer = 0;

//         Array.Sort(A);
//         Array.Sort(B);
//         for(int index = 0; index < A.Length ; index++)
//         {
//             answer += A[index] * B[B.Length - index -1];
//         }
//         return answer;
//     }
// }

//    public int solution(int[] A, int[] B) {
//        int sum_min = 0;

//             List<int> A_temp = new List<int>(A);
//             List<int> B_temp = new List<int>(B);

//             A_temp.Sort();
//             B_temp.Sort();
//             B_temp.Reverse();

//             for (int i = 0; i < A.Length; i++)
//             {
//                 sum_min += A_temp[i] * B_temp[i];
//             }

//         return sum_min;
//     }