Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 
 
Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time

class Solution {
public:
    vector<int>dx = {1,-1,0,0};
	vector<int>dy = {0,0,1,-1};
	bool isvalid(int x, int y, int n, int m,vector<vector<int>>&grid){
		return (x >=0 and x < n and y >=0 and y < m && grid[x][y]==1);
	}
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>>q;
		
		for(int i=0;i<n;i++)
		{
		    for(int j=0;j<m;j++)
		    {
		        if(grid[i][j]==2)
		        {
		            q.push({i,j});
		            grid[i][j]=10;
		        }
		    }
		}
		int ans = 0;
		while(!q.empty())
		{
		    int cnt = q.size();
		    for(int i=0;i<cnt;i++)
		    {
		        int x = q.front().first;
		        int y = q.front().second;
		        q.pop();
		        
		        for(int i=0;i<4;i++)
		        {
	                int new_x = x+dx[i];
	                int new_y = y+dy[i];
	                
	                if(isvalid(new_x,new_y,n,m,grid))
	                {
	                    q.push({new_x,new_y});
	                    grid[new_x][new_y]=10;
	                }
		        }
		    }
		    ans++;
		}
		
		for(int i=0;i<n;i++)
		{
		    for(int j=0;j<m;j++)
		    {
		        if(grid[i][j]==1)
		        return -1;
		    }
		}
		return ans-1;
    }
};