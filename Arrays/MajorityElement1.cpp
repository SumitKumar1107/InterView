Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Input: nums = [3,2,3]
Output: 3

int majorityElement(vector<int>& nums) {
        
        int majority = nums[0]; // number
        int n = nums.size();
        
        int count = 1;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]==majority)
            {
                count++;
            }
            else
            {
                count--;
            }
            if(count==0)
            {
                majority = nums[i];
                count=1;
            }
        }
        return majority;
    }