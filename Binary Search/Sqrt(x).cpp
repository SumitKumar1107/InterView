Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

Input: x = 4
Output: 2

class Solution {
public:
    int mySqrt(int x) {
        long long int low = 1;
        long long int high = x;;
        long long int ans = 1;
        
        if(x==0)
        return 0;
        
        while(low<=high)
        {
            long long int mid = (low+high)/2;
            long long int msq = (mid*mid);
            
            if(msq==x)
            return mid;
            
            if(msq>x)
                high = mid-1;
            
            else
            {
                low = mid+1;
                ans=mid;
            }
        }
        return ans;
    }
};