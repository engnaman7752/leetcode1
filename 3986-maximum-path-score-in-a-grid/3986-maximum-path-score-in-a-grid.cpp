class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int ans=solve(0,0,0,k,grid,dp);
        if(ans>=0)return ans;
        return -1;
    }
    int solve(int i,int j,int cost,int k,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        if(cost>k||i>=n||j>=m){
            return INT_MIN;
        }
        if(dp[i][j][cost]!=-1)return dp[i][j][cost];
        if(i==n-1&&j==m-1){
            if(grid[i][j]!=0)cost++;
            if(cost<=k)return grid[i][j];
            else return INT_MIN;
        }
        int down=INT_MIN;
        int right=INT_MIN;
        int l=cost;
        if(grid[i][j]!=0)l++;
        down=solve(i+1,j,l,k,grid,dp);
        right=solve(i,j+1,l,k,grid,dp);
        return dp[i][j][cost]=grid[i][j]+max(down,right);
    }
};