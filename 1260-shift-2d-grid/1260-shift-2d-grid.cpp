class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int t) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int k=t%(n*m);
                int nrow=i;
                int ncol=j;
                while(true){
                if(ncol+k>=m)
                   { k=k-(m-ncol);
                    nrow++;
                    ncol=0;
                    }
                else{
                    ncol=ncol+k;
                    break;
                }
                }
               nrow=nrow%n;
                ans[nrow][ncol]=grid[i][j];

            }
        }
        return ans;
    }
};