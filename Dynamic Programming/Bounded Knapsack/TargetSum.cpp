You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.


int dp[21][1001];
public:
    int findTargetSumWays(vector<int>&a, int s) {
      int t= accumulate(a.begin(),a.end(),0);
        if(t<s || (t+s)%2 !=0)
            return 0;
        int z=(s+t)/2;
        for(int i=0;i<=a.size();i++)
        {
            for(int j=0;j<=z;j++ )
            {
                if(i==0 && j !=0)
                    dp[i][j]=0;
                else if(i==0 && j==0)
                    dp[i][j]=1;
                else if(a[i-1]<=j)
                    dp[i][j]= dp[i-1][j-a[i-1]]+dp[i-1][j];
                 else 
                     dp[i][j]=dp[i-1][j];
                    
}
}
        return dp[a.size()][z];
    }