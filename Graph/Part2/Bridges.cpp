#include<bits/stdc++.h>
using namespace std;

vector<int>ar[100001];
int in[100001] , low[100001] , vis[100001] ,timer;
bool isbridge;
vector<pair<int , int >> edgelist;


void dfs(int node , int par)
{
  vis[node] = 1;
  in[node] = low[node] = timer;
  timer++;

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

        if(in[node]>in[child])
        edgelist.push_back({node,child});
    }
    //forward edge
    else
    {
      dfs(child,node);

      if(low[child]>in[node])
      {
        isbridge = true;
        return ;
      }

      edgelist.push_back({node,child});
      low[node] = min(low[node],low[child]);
    }
  }
}

int main()
{
  int n,m,a,b;

  cin>>n>>m;

  while(m--)
  {
    cin>>a>>b , ar[a].push_back(b) , ar[b].push_back(a);
  }

  dfs(1,-1);

  if(isbridge)
  {
    cout<<0;
  }

  else
  {
    for(auto e : edgelist)
    {
      cout<<e.first<<" "<<e.second<<endl;
    }
  }
}
