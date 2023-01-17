 static void Main(string[] args)
        {
            string test = "3people unfollowed me ";
            
            Console.Write(newSolution(test));
        }

        public static string newSolution(string s)
        {
            int[] numberArray = {0,1,2,3,4,5,6,7,8,9,10};
            bool isNumber = false;
            bool endBlank = false;
            
            List<int> blankPosition = new List<int>();
            string lowerSentence = s.ToLower();
            
            StringBuilder builder = new StringBuilder(lowerSentence);
            
            if (s.Length > 0)
            {
                for (int i = 0; i < numberArray.Length; i++)
                {
                    if (char.GetNumericValue(s[0]) == numberArray[i])
                    {
                        isNumber = true;
                    }
                }                
            }
            
            // Check blank value in order to change Capital char and save to list
            
            for (int i = 0; i < s.Length; i++)
            {
                if (i < s.Length - 2)
                {
                    if (s[i].Equals(' ') && s[i+1].Equals(' ') == false)
                    {
                        blankPosition.Add(i);
                    } else if (s[s.Length-1].Equals(" "))
                    {
                        endBlank = true;
                    }
                }
               
                
            }
            
            // Check first char whether number or not
            if (!isNumber)
            {
                builder[0] = Char.ToUpper(lowerSentence[0]);
            }

            // Change Capital char
            for (int i = 0; i < blankPosition.Count; i++)
            {
                int position = blankPosition[i];
                builder[position+1] = char.ToUpper(lowerSentence[position + 1]);
            }

            if (endBlank)
            {
                // Test case for 8, it was failure continuously..
                builder.Append(" ");
            }
            return builder.ToString();
        }