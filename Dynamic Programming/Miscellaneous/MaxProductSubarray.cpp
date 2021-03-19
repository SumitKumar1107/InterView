Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

It is guaranteed that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.


int maxProduct(vector<int>& nums) {
    if(nums.empty()) {
        return 0;
    }
    int currentMax = nums[0]; //keep track of current maximum product
    int currentMin = nums[0]; //keep track of current minimum product
    int maxProduct = nums[0]; //keep overall maximum product subarray
    
    for(int i = 1; i < nums.size(); ++i) {
       
        int p1 = currentMax * nums[i]; //calculating maximum or minimum possible product 
        int p2 = currentMin * nums[i]; //calculating maximum or minimum possible product
    
        currentMax = max(nums[i], max(p1, p2)); //taking only maximum product caluclated till now
        currentMin = min(nums[i], min(p1, p2)); //taking only minimum product calculated till now
       
        maxProduct = max(maxProduct,currentMax); //
    }
    return maxProduct;
}