Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.


int equalPartition(int N, int arr[])
    {
        // code here
        
        int sum = 0;
        for(int i=0;i<N;i++)
        sum += arr[i];
        
        if(sum%2!=0)
        return 0;
        
        int z = sum/2;
        
        bool dp[N+1][z+1];
        
        for(int i=0;i<N+1;i++)
        dp[i][0] = 1;
        
        for(int i=1;i<z+1;i++)
        dp[0][i] = 0;
        
        for(int i=1;i<N+1;i++)
        {
            for(int j=1;j<z+1;j++)
            {
                if(arr[i-1] <= j) //particular number smaller number than total sum 
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][z];
    }