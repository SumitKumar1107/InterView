Given a binary array, find the maximum number of consecutive 1s in this array.

Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
    
    
     int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int ans  = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                ans++;
            }
            else
            {
                ans  = 0;
            }
             maxi = max(maxi,ans); //this should not be in else part 
        }
        return maxi;
    }