class Solution {
public:
    int solve(int i,vector<int>&nums,int target,vector<int>&dp){
        int n=nums.size();
        if(i==n-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MIN;
        for(int index=i+1;index<n;index++){
            if(1LL*nums[i]+1LL*target>=1LL*nums[index] && 1LL*nums[i]-1LL*target <=1LL*nums[index]){
                ans=max(ans,solve(index,nums,target,dp));
            }
        }
        if(ans==INT_MIN)return dp[i]=INT_MIN;
        return dp[i]=ans+1;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int ans=solve(0,nums,target,dp);
        if(ans==INT_MIN)return -1;
        return ans;
    }
};