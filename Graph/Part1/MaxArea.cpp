You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

class Solution {
public:
    
    int dfs(int x,int y,vector<vector<int>>& grid)
    {
        if(x<0 || x>=grid.size() || y<0 || y>= grid[0].size())
        return 0;
        
        if(grid[x][y]==1)
        {
            grid[x][y] = 0;
            
            return 1+dfs(x-1,y,grid)+dfs(x+1,y,grid)+dfs(x,y-1,grid)+dfs(x,y+1,grid);
        }
        return 0;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int a = dfs(i,j,grid);
                    maxi = max(a,maxi);
                }
            }
        }
        return maxi;
    }
};