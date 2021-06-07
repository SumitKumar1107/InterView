#include<bits/stdc++.h>
using namespace std;

vector<int>ar[100001];
int in[100001];
vector<int>res;

bool kahns(int n)
{
  priority_queue<int,vector<int>,greater<int>>pq;

  for(int i=1;i<=n;i++)
  {
    if(in[i]==0)
    pq.push(i);
  }

  while(!pq.empty())
  {
    int curr = pq.top();
    res.push_back(curr);

    pq.pop();

    for(int child:ar[curr])
    {
      in[child]--;
      if(in[child]==0)
      pq.push(child);
    }
  }
  return res.size()==n;
}
int main()
{
  int n,m,a,b;
  #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

  cin>>n>>m;

  for(int i=1;i<=m;i++)
  {
    cin>>a>>b;
    ar[a].push_back(b);
    ar[b].push_back(a);
    in[b]++;
  }
  if(!kahns(n))
  cout<<"Sandro fails.";
  else
  {
    for(int node:res)
    cout<<node<<" ";
  }
}
