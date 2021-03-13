You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]

static bool cmp(vector<int>&a , vector<int>&b)
    {
        return a[0] < b[0];    
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp); //sort on basis of first value
        
        
        int lis[pairs.size()];
        lis[0]=1;
        
        for(int i=1;i<pairs.size();i++)
        {
            lis[i]=1;
            for(int j=0;j<i;j++)
            {
                if(pairs[i][0] > pairs[j][1]) //based on condition
                {
                    lis[i] = max(lis[i],lis[j]+1);
                }
            }
        }
        int n = pairs.size();
        return *max_element(lis,lis+n);
    }