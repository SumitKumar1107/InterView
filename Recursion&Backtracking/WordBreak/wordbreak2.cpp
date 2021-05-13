Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>result;
        
        map<string,vector<string>>mp; //memoization
        if(mp.find(s)!=mp.end())
            return mp[s];
        set<string>st(wordDict.begin(),wordDict.end());
        if(st.find(s)!=st.end())
        {
            result.push_back(s);
        }
        
        for(int i=1;i<=s.size();i++)
        {
            string left = s.substr(0,i); //if any part found in dictionary 
            
            if(st.find(left)!=st.end())
            {
                vector<string>sub = wordBreak(s.substr(i),wordDict); //then recursively call for right part and store as according to question
                
                for(auto str:sub)
                {
                    result.push_back(left + " " + str);
                }
            }
        }
        mp[s] = result;
        for(auto it:mp)
        {
            cout<<it.first<<endl;
        }
        return result;
    }
};