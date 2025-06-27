class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size());
        for(int i=0;i<triangle.size();i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            dp[i].push_back(-1);
        }
    
        return solve(0,0,triangle,dp); 
    } 
    int solve(int row,int col,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {if(col>=dp[row].size()||row>=dp.size()) return INT_MAX;
        if(row==triangle.size()-1)
        {
            return triangle[row][col];
        }
        if(dp[row][col]!=-1)return dp[row][col];
        int first=solve(row+1,col,triangle,dp);
        int second=solve(row+1,col+1,triangle,dp);
        return dp[row][col]=triangle[row][col]+min(first,second);
        
    }
};