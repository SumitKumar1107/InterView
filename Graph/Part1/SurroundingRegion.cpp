Given an m x n matrix board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

class Solution {
public:
    
    void dfs(vector<vector<char>>& board, int x, int y)
    {
        int m = board.size();
        int n = board[0].size();
        
        if(x<0 || y<0 || x>=m || y>=n || board[x][y]!='O')
        return;
        
         board[x][y] = '*';
        
         dfs(board,x+1,y);
         dfs(board,x-1,y);
         dfs(board,x,y+1);
         dfs(board,x,y-1);
    }
    
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<n;i++)
        {
            if(board[0][i] ==  'O')
                dfs(board,0,i);
            
            if(board[m-1][i] == 'O')
                dfs(board,m-1,i);
        }
        
        for(int i=1;i<m-1;i++)
        {
            if(board[i][0] == 'O')
                dfs(board,i,0);
            
            if(board[i][n-1]=='O')
                dfs(board,i,n-1);
        }
        
        //make corner and corner related one * and other left 'O' to 'X'
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                char c = board[i][j];
                if(c=='*')
                board[i][j] = 'O';
                else if(c=='O')
                board[i][j] = 'X';
            }
        }
    }
};