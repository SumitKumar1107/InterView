You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

Return the maximum number of envelopes can you Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.


Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

 static bool cmp(vector<int>&a , vector<int>&b)
    {
        if(a[0]==b[0]) //if first value same then 
            return a[1] < b[1]; //sort according to second value
        else
            return a[0] < b[0]; //sort according to first value
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        
        int lis[envelopes.size()];
        
        for(int i=0;i<envelopes.size();i++) //find lis based on second value
        {
            lis[i] = 1; 
            for(int j=0;j<i;j++)
            {
                if(envelopes[j][1] < envelopes[i][1] && envelopes[j][0] != envelopes[i][0])
                {
                    lis[i] = max(lis[i],lis[j]+1);
                }
            }
        }
        int n = envelopes.size();
        return *max_element(lis,lis+n);
    }