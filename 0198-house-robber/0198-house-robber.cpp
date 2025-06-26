class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(0,dp,nums);
    }
    int solve(int i,vector<int>&dp,vector<int>& nums)
    {
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int x=nums[i]+solve(i+2,dp,nums);
        int y=solve(i+1,dp,nums);
        return dp[i]=max(x,y);
    }
};