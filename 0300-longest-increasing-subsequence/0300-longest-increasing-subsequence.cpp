class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,nums,dp,-1);
        
    }
    int solve(int index,vector<int>& nums,vector<vector<int>>&dp,int pre){
        if(index==nums.size())return 0;
        if(dp[index][pre+1]!=-1)return dp[index][pre+1];
        int take=0;
        if(pre==-1||nums[index]>nums[pre]){
            take=1+solve(index+1,nums,dp,index);
           
        }
         int nott=solve(index+1,nums,dp,pre);
            return dp[index][pre+1]=max(take,nott);

    }
};