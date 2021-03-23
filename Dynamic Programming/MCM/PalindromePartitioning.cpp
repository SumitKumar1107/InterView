Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

   bool ispalin(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--])
            return false;
        }
        return true;
    }
    
    int minCut(string s) {
        int arr[s.size()+1];
        
        for(int i=0;i<=s.size();i++)
        {
            arr[i] = INT_MAX;
        }
        
        arr[s.size()-1] = 0;
        arr[s.size()] = 0;
        
        for(int i=s.size()-2;i>=0;i--)
        {
            for(int j=i;j<s.size();j++)
            {
                if(ispalin(s,i,j))
                {
                    if(j==s.size()-1)
                    {
                        arr[i]=0;
                        break;
                    }
                    int x = 1 + arr[j+1];
                    if(x<arr[i])
                    {
                        arr[i]=x;
                    }
                }
            }
        }
        return arr[0];
    }