class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
         int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<pair<int,int>>>pre(n,vector<pair<int,int>>(m,{0,0}));
        for (int i = 0; i < n; i++) {
            int countx = 0;
            int county=0;
            for (int j = 0; j < m; j++) {
                if (i == 0) {
                    if(grid[i][j]=='X')countx++;
                    else if(grid[i][j]=='Y')county++;
                    pre[i][j]={countx,county};
                } else {
                    int sumx =  pre[i - 1][j].first;
                    int sumy=pre[i - 1][j].second;
                    if(grid[i][j]=='X')countx++;
                    else if(grid[i][j]=='Y')county++;
                    pre[i][j]={sumx+countx,sumy+county};
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pre[i][j].first>0&&pre[i][j].first==pre[i][j].second)ans++;
            }
        }
        return ans;
    }
};