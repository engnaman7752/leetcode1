class Solution {
public:
vector<int>dc{1,-1,0,0};
vector<int>dr{0,0,-1,1};
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                    if(dfs(i,j,-1,-1,grid,vis))return true;
                }
            }
        }
        return false;
    }
    bool dfs(int i,int j,int px,int py,vector<vector<char>>& grid,vector<vector<int>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
             if(nr<n && nc<m && nr>=0 && nc>=0){
                if(grid[nr][nc]==grid[i][j] && vis[nr][nc]==0){
                    if(dfs(nr,nc,i,j,grid,vis)) return true;
                }
                else if(grid[nr][nc]==grid[i][j] && vis[nr][nc]==1 && nr!=px &&nc!=py)return true;
             }
        }
        return false;
    }
};