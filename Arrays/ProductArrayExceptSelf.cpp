Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

vector<int> productExceptSelf(vector<int>& nums) {
        
        /*  Numbers:     2    3    4     5
            Lefts:       1    2  2*3 2*3*4
            Rights:  3*4*5  4*5    5     1
            
        */
        
        int n = nums.size();
        vector<int>output(n);    
        
        output[0] = 1;
        
        for(int i=1;i<n;i++)
        {
            output[i] = nums[i-1]*output[i-1];
        }
        
        int prev = 1;
        for(int i=n-1;i>=0;i--)
        {
            output[i] = prev*output[i];
            prev = prev*nums[i];
        }
        return output;
    }