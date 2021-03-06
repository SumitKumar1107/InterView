Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.


1  3 5  7
10 11 16 20
23 30 34 40

Target - 2


bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)
            return false;
        int n = matrix.size();
        int m = matrix[0].size();
        
        int low  = 0;
        int high = n*m-1;
        
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            
            if(matrix[mid/m][mid%m] == target) //mid/m gives row and mid%m gives column
                return true;
            
            if(matrix[mid/m][mid%m]<target)
            {
                low = mid+1;
            }
            if(matrix[mid/m][mid%m]>target)
            {
                high = mid-1;
            }
        }
        return false;
    }