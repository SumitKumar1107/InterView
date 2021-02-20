You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

1 2 3           7 4 1
4 5 6           8 5 2
7 8 9 ------>   9 6 3

  void rotate(vector<vector<int>>& matrix) {
        //reverse and swap the symmetry
        
        reverse(matrix.begin(),matrix.end());
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=i;j<matrix[0].size();j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }

