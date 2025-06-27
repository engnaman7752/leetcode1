class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return solve(0,0,grid,dp);
    }
    int solve(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {   int n=grid[0].size();
        int m=grid.size();
        if(row>=m||col>=n)return 200000;
        if(dp[row][col]!=-1)return dp[row][col];
        if(row==m-1&&col==n-1)return grid[row][col];
        int right=grid[row][col]+solve(row,col+1,grid,dp);
        int down=grid[row][col]+solve(row+1,col,grid,dp);
        return dp[row][col]=min(right,down);
    }
};