Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?


1 1 1         1 0 1
1 0 1         0 0 0
1 1 1 ------> 1 0 1


void setZeroes(vector<vector<int>>& matrix) {
        
        bool iszerorow = false;
        bool iszerocol = false;
        
        for(int i=0;i<matrix.size();i++) //first colwise 
        {
            if(matrix[i][0] == 0)
            {
                iszerocol = true;
            }
        }
        
         for(int i=0;i<matrix[0].size();i++) //first rowwise 
        {
            if(matrix[0][i] == 0)
            {
                iszerorow = true;
            }
        }
        
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[0].size();j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(iszerorow)
        {
            for(int i=0;i<matrix[0].size();i++)
            {
                matrix[0][i] = 0;
            }
        }
        
        if(iszerocol)
        {
            for(int i=0;i<matrix.size();i++)
            {
                matrix[i][0] = 0;
            }
        }
    }