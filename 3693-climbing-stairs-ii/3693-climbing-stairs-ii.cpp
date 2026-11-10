class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        return solve(n,dp,costs);
       
    }
    int solve(int index,vector<int>&dp,vector<int>&costs){
        if(index==0)return 0;
        if(index<0)return 1e8;
        if(dp[index]!=-1)return dp[index];
        return dp[index]=costs[index-1]+min(1+solve(index-1,dp,costs),min(4+solve(index-2,dp,costs),9+solve(index-3,dp,costs)));
    }
};