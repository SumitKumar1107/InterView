Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.

Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.

class Solution {
private:
public:
	int minSwaps(vector<int>&nums){
	    // Code here
	    int n = nums.size();
	    pair<int,int>arr[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        arr[i].first=nums[i];
	        arr[i].second=i;
	    }
	    sort(arr,arr+n);
	    
	    vector<bool>vis(n,false);
	    
	    int ans = 0;
	    for(int i=0;i<n;i++)
	    {
	        if(vis[i]==true || arr[i].second == i)
	        {
	            continue;
	        }
	        
	        int cyc=0;
	        int j=i;
	        
	        while(!vis[j])
	        {
	            vis[j]=1;
	            j=arr[j].second;
	            cyc++;
	        }
	        if(cyc>0)
	        {
	            ans+=cyc-1;
	        }
	    }
	    return ans;
	}
};
