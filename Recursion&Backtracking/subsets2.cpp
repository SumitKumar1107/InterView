Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

class Solution {
public:
    vector<vector<int>>ans;
    
    void solve(vector<int>nums,int ind,vector<int>bset)
    {
        ans.push_back(bset);
        for(int i=ind;i<nums.size();i++)
        {
            if(i!=ind && nums[i]==nums[i-1])
            continue;
            
            bset.push_back(nums[i]);
            solve(nums,i+1,bset);
            bset.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>bset;
        sort(nums.begin(),nums.end());
        solve(nums,0,bset);
        return ans;
    }
    
    //https://leetcode.com/problems/subsets-ii/discuss/1095672/CPP-using-Aditya-Verma-subset-video-(12)-recursion-playlist
};