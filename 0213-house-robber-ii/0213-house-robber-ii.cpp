class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        vector<int>dp(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        return max(solve(0,dp,nums,nums.size()-1),solve(1,dp2,nums,nums.size()));
    }
    int solve(int i,vector<int>&dp,vector<int>& nums,int last)
    {
        if(i>=last) return 0;
        if(dp[i]!=-1) return dp[i];
        int x=nums[i]+solve(i+2,dp,nums,last);
        int y=solve(i+1,dp,nums,last);
        return dp[i]=max(x,y);
    }
};