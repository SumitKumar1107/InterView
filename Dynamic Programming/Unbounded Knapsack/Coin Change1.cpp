You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.


Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

 int change(int amount, vector<int>& coins) {
        
        long long m = coins.size();
        long long t[m+1][amount+1];
        long long i,j;
        
        for (i = 0; i <= m;i++) {
			t[i][0] = 1;
		}
        
        for (i = 1; i <= amount; i++) {
			t[0][i] = 0;
		}
        
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=amount;j++)
            {
                if(coins[i-1]>j)
                {
                    t[i][j] = t[i-1][j];
                }
                else
                {
                    t[i][j] = t[i-1][j] + t[i][j-coins[i-1]];
                }
            }
        }
                    
 return t[m][amount];
}