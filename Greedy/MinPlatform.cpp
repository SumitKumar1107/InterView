Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms,



Input: N = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.

int findPlatform(int arr[], int dep[], int n)
{
	// Your code here
	sort(arr,arr+n);
	sort(dep,dep+n);
	int i=1; // keep track arrival
	int j=0; // keep track departure
	int res = 1; int curr=1;
	while(i<n && j<n)
	{
	    if(arr[i]<=dep[j]) // means one more train coming as still train is there so we need one platform extra
	    {
	        curr++;
	        i++;
	    }
	    else
	    {
	        curr--;
	        j++;
	    }
	    res = max(res,curr);
	}
	return res;
}