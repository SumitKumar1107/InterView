Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

int longestConsecutive(vector<int>& nums) {
        set<int>s;
        int maxi = 0;
        
        for(auto it:nums)
        {
            s.insert(it);
        }
        int cnt = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            int cnum = nums[i];
            if(s.find(cnum-1)==s.end()) //if number-1 not present
            {
                int num = nums[i]; //then check for number+1 and so on present or not
                cnt = 1;
                
                while(s.find(num+1)!=s.end())
                {
                    num++;
                    cnt++;
                }
                maxi = max(maxi,cnt);
            }
        }
        return maxi;
    }