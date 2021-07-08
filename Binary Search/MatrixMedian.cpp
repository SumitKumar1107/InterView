Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.

Input 1:
    A = [   [1, 3, 5],
            [2, 6, 9],
            [3, 6, 9]   ]
Output 1:
    5
Explanation 1:
    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.


int countsmall(vector<int>&row,int mid)
{
    int low  = 0;
    int high = row.size()-1;

    while(low<=high)
    {
        int md = (low+high)/2;
        if(row[md]<=mid)
        low=md+1;
        else
        high=md-1;
    }
    return low;
}

int Solution::findMedian(vector<vector<int> > &A) {

    int low  = INT_MIN;
    int high = INT_MAX;

    int n = A.size();
    int m = A[0].size();

    while(low<=high)
    {
        int mid = (low+high)/2;

        int cnt = 0;

        for(int i=0;i<n;i++)
        cnt += countsmall(A[i],mid);

        if(cnt<=(n*m)/2)
        low=mid+1;

        else
        high=mid-1;
    }
    return low;
}
