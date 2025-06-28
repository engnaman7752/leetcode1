class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dp(n,vector<int>(n,-INT_MAX));
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
           ans=min(ans,solve(i,0,i,dp,grid)); 
        }
        return ans;
    }
    int solve(int last,int row,int col,vector<vector<int>>&dp,vector<vector<int>>& grid)
    {int n=grid.size();
        if(row>=n||col>=n||col<0)return INT_MAX;
        if(row==n-1) return grid[row][col];
        if(dp[row][col]!=-INT_MAX) return dp[row][col];
        int x=INT_MAX;
        for(int i=0;i<n;i++)
       { if(i!=last)
        x=min(x,solve(i,row+1,i,dp,grid));}

        return dp[row][col]=grid[row][col]+x;
    }
};