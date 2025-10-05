class Solution {
public:
vector<int>dr{1,-1,0,0};
vector<int>dc{0,0,1,-1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>pacific(n,vector<int>(m));
        vector<vector<int>>atlantic(n,vector<int>(m));
        for(int i=0;i<n;i++)dfs(i,0,heights,pacific);
        for(int i=0;i<m;i++)dfs(0,i,heights,pacific);
        for(int i=0;i<n;i++)dfs(i,m-1,heights,atlantic);
        for(int i=0;i<m;i++)dfs(n-1,i,heights,atlantic);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    if(pacific[i][j]==atlantic[i][j]&&pacific[i][j]==1)ans.push_back({i,j});
            }
        }
        return ans;
    }
    void dfs(int row,int col,vector<vector<int>>&heights,vector<vector<int>>&vis){
        int n=heights.size();
        int m=heights[0].size();
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int newr=row+dr[i];
            int newc=col+dc[i];
            if(newr>=n||newc>=m||newr<0||newc<0)continue;
            if(vis[newr][newc])continue;
            if(heights[row][col]<=heights[newr][newc])
            dfs(newr,newc,heights,vis);
        }
    }
};