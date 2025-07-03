class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for(int i=0;i<n;i++)
        {
            totalSum=totalSum+nums[i];
        }
        if(totalSum%2!=0)return false;
        int target=totalSum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(0,target,nums,dp);
    }
    bool solve(int index,int target,vector<int>& nums,vector<vector<int>>& dp){
        int n=nums.size();
        if(index==n)return false;
        if(target==0) return true;
        if(dp[index][target]!=-1)return dp[index][target];
        bool take = false;
        if(nums[index] <= target) {
            take = solve(index + 1, target - nums[index], nums, dp);
        }
        bool notTake=solve(index+1,target,nums,dp);
        return dp[index][target]=take||notTake;

    }
};