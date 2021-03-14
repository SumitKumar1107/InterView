You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).


Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3

int knapSack(int w, int wt[], int val[], int n) 
{ 
   // Your code here
   
   int dp[n+1][w+1];
   
   for(int i=0;i<=w;i++)
   {
       dp[0][i] = 0;
   }
   
   for(int j=0;j<=n;j++)
   {
       dp[j][0] = 0;
   }
   
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=w;j++)
       {
           if(wt[i-1]>j) //particular weight should be less than total sum
           {
               dp[i][j] = dp[i-1][j];
           }
           else
           {
               dp[i][j] = max(dp[i-1][j],dp[i-1][j-wt[i-1]] + val[i-1]);
           }
       }
   }
   
   return dp[n][w];
}