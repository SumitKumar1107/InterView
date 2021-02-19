Share
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

Input: nums = [1,2,3]
Output: [1,3,2]


 void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int k,l;
        
        for(k=n-2;k>=0;k--) // find first where nums[i]<nums[i+1] traverse from back 
        {
            if(nums[k]<nums[k+1])
            {
                break;
            }
        }
            if(k<0) //if no then reverse just
            {
                reverse(nums.begin(),nums.end());
            }
            else
            {
                for(l=n-1;l>k;l--) // then find the point who is greater than k index
                {
                    if(nums[l]>nums[k])
                    {
                        break;
                    }
                }
                swap(nums[l],nums[k]);
                reverse(nums.begin()+k+1,nums.end());
            }
    }