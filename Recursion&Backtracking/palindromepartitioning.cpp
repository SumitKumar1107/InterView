Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]


class Solution {
public:
    bool ispalin(string s, int low, int high)
    {
        while(low<=high)
        {
            if(s[low++]!=s[high--])
            return false;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<string>tmp;
        vector<vector<string>>ans;
        solve(s,0,tmp,ans);
        return ans;
    }
    
    void solve(string s,int start, vector<string>&tmp, vector<vector<string>>&ans)
    {
        if(s.size()==start)
        ans.push_back(tmp);
        
        for(int i=start;i<s.size();i++)
        {
            if(ispalin(s,start,i))
            {
                tmp.push_back(s.substr(start,i-start+1)); //index and length till where you want substring
                solve(s,i+1,tmp,ans);
                tmp.pop_back();
            }
        }
    }
};