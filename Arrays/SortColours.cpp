Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

 void sortColors(vector<int>& nums) {
        
        
        int lo = 0;
        int md = 0;
        int hg = nums.size()-1;
        
        while(md<=hg)
        {
            if(nums[md] == 0)
            {
                swap(nums[lo],nums[md]);
                lo++;
                md++;
            }
            else if(nums[md]==1)
            {
                md++;
            }
            else
            {
                swap(nums[md],nums[hg]);
                hg--;
            }
        }
    }