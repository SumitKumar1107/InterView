Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]


vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            if(i==0 || i>0 && nums[i]!=nums[i-1])
            {
                int l = i+1;
                int r = nums.size()-1;
                
                while(l<r)
                {
                    int sum = nums[i]+nums[l]+nums[r];
                    if(sum==0)
                    {
                        ans.push_back(vector<int>{nums[i],nums[l],nums[r]});
                        while(l<r && nums[l]==nums[l+1]) l++; //to avoid duplication
                        while(l<r && nums[r]==nums[r-1]) r--; //to avoid duplication innerwise
                        l++,r--;
                    }
                    else if(sum>0)
                    {
                        r--;
                    }
                    else
                    {
                        l++;
                    }
                }
            }
        }
        return ans;
    }