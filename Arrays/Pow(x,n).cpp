Implement pow(x, n), which calculates x raised to the power n (i.e. xn).

Input: x = 2.00000, n = 10
Output: 1024.00000

 double myPow(double x, int n) {
        double ans = 1.0;
        long long nn;
        nn=n;
        
        if(nn<0)
        {
            nn *= -1;
        }
        
        while(nn)
        {
            if(nn%2)
            {
                ans *= x;
                nn-=1;
            }
            else
            {
                x = x*x;
                nn=nn/2;
            }
        }
        if(n<0)
        {
            ans = double(1.0)/double(ans);
        }
        return ans;
    }