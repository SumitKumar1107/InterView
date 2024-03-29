You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

 
    int house(vector<int>&nums)
    {
        int dp[nums.size()];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        
        for(int i=2;i<nums.size();i++)
        {
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[nums.size()-1];
    }
    
    int rob(vector<int>& nums) {
        
        
        if(nums.size()==0)
            return 0;
        
        if(nums.size()==1)
            return nums[0];
        
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        vector<int>v1(nums.begin(),nums.end()-1); //considering start part so we can't chose end part as everything in circle
        vector<int>v2(nums.begin()+1,nums.end()); //considering end part so we can't chose start part as everything in circle
        return max(house(v1),house(v2));
    }