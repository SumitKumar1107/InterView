#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>adj[1001];

int main()
{
	int n,m;
	cin>>n>>m;

	while(m--)
	{
		int a,b,w;
		cin>>a>>b>>w;
		adj[a].push_back({b,w});
		adj[b].push_back({a,w});
	}

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

	vector<int>key(n+1,INT_MAX);
	vector<bool>mset(n+1,false);

	key[1]=0;
	pq.push({0,1}); //weight node
	while(!pq.empty())
	{
		int n = pq.top().second;
		mset[n]=true;
		pq.pop();
		for(auto it:adj[n])
		{
			int v = it.first;
			int w = it.second;
			if(mset[v]==false && w<key[v])
			{
				key[v]=w;
				pq.push({key[v],v});
			}
		}
	}
	for(int i=1;i<=n;i++)
	cout<<key[i]<<" ";
}
