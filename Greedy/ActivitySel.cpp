Example 2 : Consider the following 6 activities 
sorted by by finish time.
     start[]  =  {1, 3, 0, 5, 8, 5};
     finish[] =  {2, 4, 6, 7, 9, 9};
A person can perform at most four activities. The 
maximum set of activities that can be executed 
is {0, 1, 3, 4} [ These are indexes in start[] and 
finish[] ]


bool comp(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}

class Solution{
    public:
        int maxActivities(int start[], int end[], int n) {
        // Your code here
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back(make_pair(start[i],end[i]));
        }
        
        sort(v.begin(),v.end(),comp);
        
        int prev = 0;
        int res  = 1;
        
        for(int i=1;i<n;i++)
        {
            if(v[i].first > v[prev].second)
            {
                res++;
                prev = i;
            }
        }
        return res;
    }
};