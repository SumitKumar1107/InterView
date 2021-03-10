There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time? Also note start time of one chosen meeting can't be equal to the end time of the other chosen meeting.



Input:
N = 6
S[] = {1,3,0,5,8,5}
F[] = {2,4,6,7,9,9}
Output: 
4
Explanation:
Four meetings can be held with
given start and end timings.

bool comp(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}

class Solution{
    public:
        int maxMeetings(int start[], int end[], int n) {
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