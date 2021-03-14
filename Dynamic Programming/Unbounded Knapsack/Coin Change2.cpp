You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

int coinChange(vector<int>& coins, int amount) {
       int n = coins.size();
       int dp[n+1][amount+1];
        
       for(int i=1;i<=amount;i++)
       {
           dp[0][i] = INT_MAX-1; 
       }
        
       for(int i=0;i<=n;i++)
       {
           dp[i][0] = 0;
       }
        
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=amount;j++)
           {
               if(j<coins[i-1])
               {
                   dp[i][j] = dp[i-1][j];
               }
               else
               {
                   dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
               }
           }
       }
        
        if(dp[n][amount]==INT_MAX-1)
            return -1;
        else
            return dp[n][amount];
    }