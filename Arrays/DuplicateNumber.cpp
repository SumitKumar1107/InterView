Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

Input: nums = [1,3,4,2,2]
Output: 2


int findDuplicate(vector<int>& nums) { 
       
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        fast = 0;
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }