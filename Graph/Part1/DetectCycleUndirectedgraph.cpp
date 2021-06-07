Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

class Solution {
public:

    bool dfs(int node,int par,vector<bool>&vis,vector<int>adj[])
    {
        vis[node]=true;
        
        for(auto child:adj[node])
        {
            if(vis[child]==0)
            {
                if(dfs(child,node,vis,adj)==true)
                return true;
            }
            else
            {
                if(child!=par||child==node)
                return true;
            }
        }
        return false;
    }
    
	bool isCycle(int V, vector<int>adj[]){
	    // Code here
	    vector<bool>vis(V);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==0 && dfs(i,-1,vis,adj))
	        return true;
	    }
	    return false;
	}
};