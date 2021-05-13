Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        vector<int>dp(n+1,false); //dp[i] is set to true if a valid word (word sequence) ends there
        set<string>st(wordDict.begin(),wordDict.end());
        
        dp[0] =true;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(st.find(word)!= st.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }   
                }
            }
        }
        return dp[n];
    }
};