class Solution {
public:
vector<int>r{0,0,1,-1};
vector<int>c{1,-1,0,0};
    void bfsa(int i,int j,vector<vector<bool>>&vis,vector<vector<int>>& grid){
         int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            auto [i,j]=q.front();
            //grid[i][j]=2;
            vis[i][j]=true;
            q.pop();
            for(int l=0;l<4;l++){
                int row=i+r[l];
                int col=j+c[l];
                if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==0 && vis[row][col]==false){
                    q.push({row,col});
                }
            }
        }

    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                bfsa(i,0,vis,grid);
            }
            if(grid[i][m-1]==0){
                bfsa(i,m-1,vis,grid);
            }
        }
        for(int i=0;i<m;i++){
             if(grid[0][i]==0){
                bfsa(0,i,vis,grid);
            }
            if(grid[n-1][i]==0){
                bfsa(n-1,i,vis,grid);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && vis[i][j]==false){
                    cnt++;
                    bfsa(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};