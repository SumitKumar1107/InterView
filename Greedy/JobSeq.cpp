Given a set of N jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

Note: Jobs will be given in the form (Job id, Deadline, Profit) associated to that Job.


bool comp(Job a , Job b)
{
    return a.profit > b.profit; 
}

class Solution {
  public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comp); // sort job according to higher profit
        
        int maxi = arr[0].dead;
        
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,arr[i].dead);
        }
        
        int slot[maxi+1]; //creating slot on basis for maximum deadline
        
        for(int i=0;i<=maxi;i++)
        slot[i] = -1;
        
        int ans = 0;
        int profi = 0;
        
        //now iterate over every job in array and tried completing job in latest manner
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j--)
            {
                if(slot[j]==-1)
                {
                    slot[j]=i;
                    ans++;
                    profi+=arr[i].profit;
                    break;
                }
            }
        }
        
        vector<int>v;
        v.push_back(ans);
        v.push_back(profi);
        return v;
    } 
};