You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.

vector<vector<int>>t;
    
    int solve(int e,int n)
    {
        if(n==0 || n==1)
            return n;
        
        if(e==1)
            return n;
        if(t[e][n]!=-1)
            return t[e][n];
        
        int mn = INT_MAX,l=1,h=n;
        
        while(l<=h)
        {
            int mid = (l+h)/2;
            int low = solve(e-1,mid-1); //if egg break
            int high = solve(e,n-mid);  //if egg don't break
            int temp = 1+max(low,high); // break and not break take worst case
            mn = min(mn,temp);
            if(low<high) //worst max upper case
            {
                l = mid+1;
            }
            else
            {
                h = mid-1;
            } 
        }
        return t[e][n]=mn;  
    }
    int superEggDrop(int e, int n) {
        t.resize(e+1,vector<int> (n+1,-1));
        return solve(e,n);
    }