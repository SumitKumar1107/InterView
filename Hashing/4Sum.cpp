Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

 vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();)
        {
            for(int j=i+1;j<nums.size();)
            {
                int l = j+1;
                int r = nums.size()-1;
                
                while(l<r)
                {
                    int sum = nums[i]+nums[j]+nums[l]+nums[r];
                
                if(sum>target)
                {
                    r--;
                }
                else if(sum<target)
                {
                    l++;
                }
                else
                {
                     ans.push_back(vector<int>{nums[i],nums[j],nums[l],nums[r]});
                     while(l<r && nums[l]==nums[l+1]) l++; //to avoid duplication
                     while(l<r && nums[r]==nums[r-1]) r--; //to avoid duplication innerwise
                     l++,r--;
                }
                }
             while(j+1<nums.size() && nums[j]==nums[j+1]) j++;
                
                j++;
            }
            while(i+1<nums.size() && nums[i]==nums[i+1] ) i++;
            
            i++;
        }
     return ans;   
    }