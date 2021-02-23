Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.


Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

 vector<int> twoSum(vector<int>& nums, int target) {
        
        
        vector<int>ans;
        map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i]) != mp.end())
            {
                ans.push_back(mp[target-nums[i]]);//first number index
                ans.push_back(i); //second number index
                return ans;
            }
            mp[nums[i]] = i; //storing number and their indices in map
        }
        return ans;
    }