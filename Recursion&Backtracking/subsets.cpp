Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>nums,int ind, vector<int>&bset)
    {
        ans.push_back(bset);
        for(int i=ind;i<nums.size();i++)
        {
            bset.push_back(nums[i]);
            solve(nums,i+1,bset);
            bset.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>bset; //storing set of number generating
        solve(nums,0,bset);
        return ans;
    }
    //https://leetcode.com/problems/subsets/discuss/27281/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)
};