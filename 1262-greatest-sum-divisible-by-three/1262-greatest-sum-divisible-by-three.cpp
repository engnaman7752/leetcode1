class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
    
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return solve(0,0,nums,dp);
    }
    int solve(int i,int rem,vector<int>&nums,vector<vector<int>>&dp){
       int n=nums.size();
        if(i==n){
            if(rem==0)return 0;
            else return INT_MIN;
        }
        if(dp[i][rem]!=-1)return dp[i][rem];
        int take=nums[i]+solve(i+1,(rem+nums[i])%3,nums,dp);
        int skip=solve(i+1,rem,nums,dp);
        return dp[i][rem]=max(take,skip);
    }
};