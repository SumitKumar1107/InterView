You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
     
        int n = nums.size();
        int low  = 0;
        int high = n-1;
        
        while(low<high)
        {
            int mid = low+(high-low)/2;
            
            if(mid%2==0 && nums[mid]==nums[mid+1]) //fullfilling condition
            low = mid+2;
            else if(mid%2==1 && nums[mid]==nums[mid-1]) //fullfilling condition
            low=mid+1;
            else
            high=mid;
        }
        return nums[low];
    }
};