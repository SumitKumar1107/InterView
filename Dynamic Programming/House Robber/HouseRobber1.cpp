You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

 int rob(vector<int>& nums) {
       if(nums.size()==0)
           return 0;
        
        if(nums.size()==1)
            return nums[0];
        
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        
        int dp[nums.size()]; //maximum money can be rob at ith considering this amount keep relevating the condition
        
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        
        for(int i=2;i<nums.size();i++)
        {
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[nums.size()-1];
    }