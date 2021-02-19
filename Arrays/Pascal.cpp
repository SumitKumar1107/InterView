Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

1
11
121
1331
14641


 vector<vector<int>> generate(int numRows) {
        vector<vector<int>>output(numRows);
        if(numRows==0)
            return output;
        
        output[0].push_back(1);
        if(numRows==1)
            return output;
        
        output[1].push_back(1);
        output[1].push_back(1);
        
        if(numRows==2)
            return output;
        
        for(int i=2;i<numRows;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                {
                    output[i].push_back(1);
                }
                else
                {
                    int sum = output[i-1][j-1]+output[i-1][j];
                    output[i].push_back(sum);
                }
            }
        }
        return output;
    }