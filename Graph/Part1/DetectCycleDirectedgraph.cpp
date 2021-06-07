Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

class Solution {
public:

    bool dfs(int node, vector<int>adj[], vector<bool>&vis,vector<bool>&rec)
    {
        vis[node]=true;
        rec[node]=true;
        
        for(int child:adj[node])
        {
            if(vis[child]==0 && dfs(child,adj,vis,rec))
            return true;
            
            if(rec[child]==true)
            return true;
        }
        rec[node]=false;
        return false;
    }
    
	bool isCyclic(int V, vector<int> adj[]) {
	   	// code here
	   	vector<bool>vis(V,false);
	   	vector<bool>rec(V,false);
	   	
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(vis[i]==0 && dfs(i,adj,vis,rec))
	   	    return true;
	   	}
	   	return false;
	}
};