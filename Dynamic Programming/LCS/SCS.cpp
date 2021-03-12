Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  If multiple answers exist, you may return any of them.

(A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the characters are chosen anywhere from T) results in the string S.)

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.

string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
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
                if(str1[i-1]==str2[j-1])
                {
                    t[i][j] = 1+t[i-1][j-1];
                }
                else
                {
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        string ans="";
        int i=n,j=m;
        
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans += str1[i-1];
                i--;
                j--;
            }
            else
            {
                if(t[i][j-1]>t[i-1][j])
                {
                    ans += (str2[j-1]);
                    j--;
                }
                else
                {
                    ans += (str1[i-1]);
                    i--;
                }
            }
        }
        
        while(i>0)
        {
            ans += (str1[i-1]);
            i--;
        }
        while(j>0)
        {
            ans += (str2[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end()); 
        return ans;
    }