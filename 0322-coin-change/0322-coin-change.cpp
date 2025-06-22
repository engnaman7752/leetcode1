class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        solve(amount,coins,dp);
        if(dp[amount]!=INT_MAX)
        return dp[amount];
        else
        return -1;

    }
    int solve(int amount,vector<int>& coins,vector<int>& dp)
    {
        if(amount==0)return dp[0]=0;
        if(amount<0)return INT_MAX;
        if(dp[amount]!=-1)return dp[amount];
        int minCoins=INT_MAX;
        for(int i=0;i<coins.size();i++)
        {int t=solve(amount-coins[i],coins,dp);
        if(t!=INT_MAX)
        t=t+1;
        minCoins=min(t,minCoins);    
        }
        return dp[amount]=minCoins;
    }
};