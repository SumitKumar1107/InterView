We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

Input: s1 = "great", s2 = "rgeat"
Output: true

unordered_map<string,int>mp;
    
    bool solve(string a,string b)
    {
        if(a==b)
        return true;
        else if(a.length()<=1)
        return false;
        
        string key = a+" "+b;
        
        if(mp.find(key)!=mp.end())
        return mp[key];
        
        int n = a.length();
        bool flag = false;
        
        for(int i=1;i<=n-1;i++)
        {
            bool cond1=(solve(a.substr(0, i),b.substr(n - i,n)) && solve(a.substr(i, n),b.substr(0, n-i)));//swap
         
            bool cond2=(solve(a.substr(0, i),b.substr(0, i))  && solve(a.substr(i, n),b.substr(i, n)));//no swap
 
             if(cond1 || cond2){
                flag = true;
                break;
            }
        }
        return mp[key]=flag;
    }
    
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length())
            return false;
        
        return solve(s1,s2);
    }