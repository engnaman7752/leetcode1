class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return solve(0,amount,coins,dp);
     }
     int solve(int index,int amount, vector<int>& coins,vector<vector<int>>& dp){
        int n=coins.size();
        if(amount==0)return 1;
        if(index==n||amount<0)return 0;
        if(dp[index][amount]!=-1)return dp[index][amount];
        int take=solve(index,amount-coins[index],coins,dp);
        int notTake=solve(index+1,amount,coins,dp);
        return dp[index][amount]=take+notTake;

     }

};