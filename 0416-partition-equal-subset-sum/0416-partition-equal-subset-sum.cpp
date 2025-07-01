class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for(int i=0;i<n;i++)
        {
            totalSum=totalSum+nums[i];
        }
        vector<vector<int>>dp(n,vector<int>(totalSum+1,-1));
        return solve(0,0,totalSum,nums,dp);
    }
    bool solve(int index,int sum,int totalSum,vector<int>& nums,vector<vector<int>>& dp){
        int n=nums.size();
        if(sum==(totalSum-sum)) return true;
        if(index>=n)return false;
        if(dp[index][sum]!=-1)return dp[index][sum];
        bool take=solve(index+1,sum+nums[index],totalSum,nums,dp);
        bool notTake=solve(index+1,sum,totalSum,nums,dp);
        return dp[index][sum]=take||notTake;

    }
};