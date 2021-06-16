#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>adj[1001];

int main()
{
    int n,m;

    cin>>n>>m; //n - vertices m- edges

    while(m--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    vector<int>dist(n+1,INT_MAX);
    int s;
    cin>>s;
    dist[s]=0;

    pq.push({0,s}); //weight node

    while(!pq.empty())
    {
        int d = pq.top().first;
        int n = pq.top().second;

        pq.pop();

        for(pair<int,int>edge:adj[n])
        {
            if(d+edge.second<dist[edge.first])
            {
                dist[edge.first] = d+edge.second;
                pq.push({dist[edge.first],edge.first});
            }
        }
    }
    for(int i=1;i<=n;i++)
    cout<<dist[i]<<" ";
}
