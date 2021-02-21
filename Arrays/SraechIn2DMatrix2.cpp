Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

1 4 7 11 15
2 5 8 12 19
3 6 9 16 22

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,r=matrix[0].size()-1;
        while(r>=0 && l<matrix.size())
        {
            if(matrix[l][r]==target) return true;
            else if(matrix[l][r]<target) l++;
            else r--;
        }
        return false;
    }