#include<bits/stdc++.h>
using namespace std;

vector<int>ar[100001];
int in[100001] , low[100001] , vis[100001] ,timer;
set<int>s;

void dfs(int node , int par)
{
  vis[node] = 1;
  in[node] = low[node] = timer;
  timer++;
  int child_cnt = 0;// for root to check it's articulation point or not

  for(auto child:ar[node])
  {
    //case 1

    if(child == par) continue;

    //case 2
    // back edge
    if(vis[child])
    {
        low[node] = min(low[node],in[child]);
        // descendant
    }
    //forward edge
    else
    {
      dfs(child,node);
      child_cnt++;
      low[node] = min(low[node],low[child]);
      if(low[child]>=in[node] && par!=-1)
      s.insert(node);
    }
  }
  cout<<child_cnt<<endl;
  if(par == -1 && child_cnt>1)
  s.insert(node);
}

int main()
{
  int n,m,a,b;
  #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
  while(1)
  {
    cin>>n>>m;
    if(n==0 && m==0)
    break;

    for(int i=1;i<=n;i++)
    ar[i].clear(), vis[i] = 0;
    s.clear();
    while(m--)
    {
      cin>>a>>b , ar[a].push_back(b) , ar[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
      if(vis[i]==0)
      dfs(i,-1); // this would be -1 bcz as it is root and not be traversed yet
    }
    cout<<s.size()<<"hy"<<endl;
  }
}
