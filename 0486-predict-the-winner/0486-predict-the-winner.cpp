class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,n-1,dp,nums)>=0;
    }
    int solve(int i,int j, vector<vector<int>>&dp,vector<int>&nums){
        if(i>j)return 0;
        if(i==j)return nums[i];
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=max(nums[i]-solve(i+1,j,dp,nums),nums[j]-solve(i,j-1,dp,nums));
    }
};