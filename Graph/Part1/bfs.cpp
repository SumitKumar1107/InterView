#include<bits/stdc++.h>
using namespace std;
vector<int>ar[100001];
int vis[100001],dist[100001];

void bfs(int src)
{
  queue<int>q;
  q.push(src);
  vis[src] =  1;
  dist[src] = 0;

  while(!q.empty())
  {
    int curr = q.front();
    q.pop();

    for(int child:ar[curr])
    {
      if(vis[child]==0)
      {
        q.push(child);
        dist[child] = dist[curr] + 1;
        vis[child] = 1;
      }
    }
  }
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

  long long t,n,m,a,b;
  cin>>t;

  while(t--)
  {
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    ar[i].clear(), vis[i]=0;

    while(m--)
    cin>>a>>b , ar[a].push_back(b) , ar[b].push_back(a);

    bfs(1);

    cout<<dist[n]<<endl;
  }
	return 0;
}
