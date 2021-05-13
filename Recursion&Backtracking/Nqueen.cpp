The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>>ans;
       vector<string>nqueen(n,string(n,'.'));
       solve(ans,nqueen,0,n); //row
       return ans;
    }
    
    void solve(vector<vector<string>>&ans,vector<string>&nqueen,int row,int n)
    {
        if(row==n)
        ans.push_back(nqueen);
        
        for(int col=0;col!=n;col++)
        {
            if(isvalid(nqueen,row,col,n))
            {
                nqueen[row][col]='Q';
                solve(ans,nqueen,row+1,n);
                nqueen[row][col]='.';
            }
        }
    }
    
    bool isvalid(vector<string>&nqueen,int row,int col,int n)
    {
        for(int i=0;i!=row;i++)
        {
            if(nqueen[i][col]=='Q')
            return false;
        }
        
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
        {
            if(nqueen[i][j]=='Q')
            return false;
        }
        for(int i=row-1,j=col+1;i>=0&&j>=0;i--,j++)
        {
            if(nqueen[i][j]=='Q')
            return false;
        }
        return true;
    }
};