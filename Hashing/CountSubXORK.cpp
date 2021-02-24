Given an array of integers arr[] and a number m, count the number of subarrays having XOR of their elements as m.

Input : arr[] = {4, 2, 2, 6, 4}, m = 6
Output : 4
Explanation : The subarrays having XOR of 
              their elements as 6 are {4, 2}, 
              {4, 2, 2, 6, 4}, {2, 2, 6},
               and {6}
               


void solve(vector<int>&a,int k)
{
    map<int,int>mp; //storing precomputed xor and how many times it appeared
    
    int cnt  = 0;
    int xorr = 0;
    
    for(auto it:a)
    {
        xorr = xorr^it;
        if(xorr==k)
        cnt++; 
        
        if(mp[xorr^k]!=mp.end()) xr^k = y so y many be different that what we are calculating 
        {
            cnt += mp[xorr^k];
        }
        mp[xorr] += 1;
    }
    return cnt;
}
               