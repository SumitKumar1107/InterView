Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

int trap(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size()-1;
        
        int leftmax = 0, rightmax = 0;
        
        while(l<=r)
        {
            if(height[l]<=height[r]) //move to bar where height is low and here we already know right side is already higher so just check leftmax w.r.t to current size and calculate the tap water 
            {
                if(height[l]<leftmax)
                {
                    ans += (leftmax-height[l]); //if current size is lower than leftmax then calculate tap water 
                }
                else
                {
                    leftmax = height[l]; //current size is greater or equal to leftmax so change leftmax to this bar 
                }
                l++;
            }
            else
            {
                if(height[r]<rightmax)
                {
                    ans += (rightmax-height[r]);
                }
                else
                {
                    rightmax = height[r];
                }
                r--;
            }
        }
        return ans;
    }