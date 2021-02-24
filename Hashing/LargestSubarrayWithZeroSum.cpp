Given an array of integers, find the length of the longest sub-array with sum equals to 0.

Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
Output: 5
Explanation: The longest sub-array with 
elements summing up-to 0 is {-2, 2, -8, 1, 7}

int solve()
{
    unordered_map<int,int>mp;
    
    int maxi=0;
    int sum =0;
    
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        if(sum==0)
        maxi = i+1;
        else
        {
            if(mp.find(sum)!=mp.end()) //if current sum appeared again it means there is some part which conatins zero so calculate length
            {
                maxi = max(maxi,i-mp[sum]);
            }
            else
            mp[sum]=i; //storing sum with index
        }
    }
    return maxi;
}