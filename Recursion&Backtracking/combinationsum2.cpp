Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

class Solution {
public:
    void solve(int ind,vector<int>& candidates,int target,vector<vector<int>>&ans,vector<int>&tmp)
    {
        if(target==0)
        ans.push_back(tmp);
        
        if(target<0)
        return;
        
        for(int i=ind;i<candidates.size();i++)
        {
            if(i!=ind && candidates[i]==candidates[i-1]) //skipping duplicates
            continue;
            
            tmp.push_back(candidates[i]);
            solve(i+1,candidates,target-candidates[i],ans,tmp);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        vector<vector<int>>ans;
        vector<int>tmp;
        solve(0,candidates,target,ans,tmp);
        return ans;
    }
};