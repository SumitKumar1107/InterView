Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(nums,temp,ans);
        return ans;
    }
    
    void solve(vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(find(temp.begin(),temp.end(),nums[i]) != temp.end()) //element already present continue directly
            continue;
            
            temp.push_back(nums[i]);
            solve(nums,temp,ans);
            temp.pop_back();
        }
    }
};