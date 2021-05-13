Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.

INPUT:
N = 4
M = 3
E = 5
Edges[] = {(1,2),(2,3),(3,4),(4,1),(1,3)}
Output: 1
Explanation: It is possible to colour the
given graph using 3 colours.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

bool issafe(int v,bool graph[101][101],int color[],int c,int m,int V)
{
    for(int i=0;i<V;i++)
    {
        if(graph[v][i] && c==color[i])
        return false;
    }
    return true;
}


bool graphutil(bool graph[101][101],int m,int color[],int v,int V)
{
    if(v==V)
    return true;
    
    for(int c=1;c<=m;c++)
    {
        if(issafe(v,graph,color,c,m,V))
        {
            color[v] = c;
            if(graphutil(graph,m,color,v+1,V)==true)
            return true;
            
            color[v] = 0;
        }
    }
    return false;
}




bool graphColoring(bool graph[101][101], int m, int V) {
    // your code here
    
    int color[V];
    for(int i=0;i<V;i++)
    {
        color[i] = 0;
    }
    
    if(graphutil(graph,m,color,0,V)==false)
    return false;
    
    return true;
}


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends