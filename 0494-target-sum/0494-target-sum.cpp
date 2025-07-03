class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)sum=sum+nums[i];
        if (target > sum || target < -sum) return 0;
        vector<vector<int>>dp(n,vector<int>(sum+1+sum,-1));
        return solve(0,target,dp,nums,sum);       
    }
    int solve (int index,int target,vector<vector<int>>&dp,vector<int>& nums,int sum){
        int n=nums.size();
        if (target + sum < 0 || target + sum >= 2 * sum + 1)
            return 0;
        if(index==n)
        {if(target==0)return 1;
        else return 0; }
        if(dp[index][target+sum]!=-1)return dp[index][target+sum];
        int positive=solve(index+1,target-nums[index],dp,nums,sum);
        int negative=solve(index+1,target+nums[index],dp,nums,sum);
        return dp[index][target+sum]=positive+negative;
    }
};