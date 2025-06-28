class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-INT_MAX));
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
           ans=min(ans,solve(0,i,dp,matrix)); 
        }
        return ans;
    }
    int solve(int row,int col,vector<vector<int>>&dp,vector<vector<int>>& matrix)
    {int n=matrix.size();
        if(row>=n||col>=n||col<0)return INT_MAX;
        if(row==n-1) return matrix[row][col];
        if(dp[row][col]!=-INT_MAX) return dp[row][col];
        int down=solve(row+1,col,dp,matrix);
        int left=solve(row+1,col-1,dp,matrix);
        int right=solve(row+1,col+1,dp,matrix);
        return dp[row][col]=matrix[row][col]+min({down,left,right});
    }
};