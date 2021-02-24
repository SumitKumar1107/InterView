Given a string s, find the length of the longest substring without repeating characters.

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

int lengthOfLongestSubstring(string s) {
        
        vector<int>mp(256,-1); //maximum 256 character can possible and storing the index where character is now 
        
        int left  = 0 ; //mainly used to jump inorder to make substring free from duplicate
        int right = 0;
        int len   = 0;
        
        int n = s.size();
        
        while(right<n)
        {
            if(mp[s[right]]!=-1) //if element is present already 
            {
                left = max(left,mp[s[right]]+1); //then jump to index found + 1 so to avoid duplicate
            }
            mp[s[right]] = right; //always updating where character is now
            len = max(len,right-left+1);
            right++;
        }
        return len;
    }