Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.


Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".


int longestPalindromeSubseq(string s) {
        string p;
        p=s;
        reverse(p.begin(),p.end());
        int n = s.size();
        int m = p.size();
        
        int t[n+1][m+1];
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0||j==0)
                    t[i][j]=0;
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(s[i-1]==p[j-1])
                {
                    t[i][j] = 1+t[i-1][j-1];
                }
                else
                {
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }