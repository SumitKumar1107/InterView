Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
 
 
 class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>tmp;
        vector<vector<int>>ans;
        vector<bool>used(nums.size(),false);
        
        solve(nums,tmp,ans,used);
        return ans;
    }
    
    void solve(vector<int>nums,vector<int>&tmp,vector<vector<int>>&ans,vector<bool>&used)
    {
        if(tmp.size()==nums.size())
        {
            ans.push_back(tmp);
            for(auto it:used)
            cout<<it<<" ";
            
            cout<<endl;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && used[i-1]==true && nums[i]==nums[i-1])
            continue;
            
            if(used[i]==false)
            {
                cout<<i<<endl;
                tmp.push_back(nums[i]);
                used[i]=true;
                solve(nums,tmp,ans,used);
                used[i]=false;
                tmp.pop_back();
            }
        }
    }
};