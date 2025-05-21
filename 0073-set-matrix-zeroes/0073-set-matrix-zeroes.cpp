class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<bool>col(m,false);
        vector<bool>row(n,false);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    col[j]=true;
                    row[i]=true;
                    

                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(row[i])
            {
                for(int l=0;l<m;l++)
                {
                    matrix[i][l]=0;
                }
            }}
            for(int i=0;i<m;i++)
        {
            if(col[i])
            {
                 for(int l=0;l<n;l++)
                {
                    matrix[l][i]=0;
                }
            }
        }
    }
};