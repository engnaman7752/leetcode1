class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int rmax=0;
        int rmin=n;
        int cmin=m;
        int cmax=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
               { rmax=max(rmax,i);
                rmin=min(rmin,i);
                cmax=max(cmax,j);
                cmin=min(cmin,j);}
            }
        }
        return (rmax-rmin+1)*(cmax-cmin+1);
    }
};