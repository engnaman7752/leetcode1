class Solution {
    const int MOD=1e9+7;
public:
    int countStableSubsequences(vector<int>& nums) {
        int n=nums.size();
        int pre1=2;
        int pre2=2;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(3,vector<int>(3,-1)));
        return solve(0,pre1,pre2,nums,dp)%MOD;
    }
    int solve(int i,int pre1,int pre2,vector<int>& nums,vector<vector<vector<int>>>&dp){
        int n=nums.size();
        if(i==n){
            if(pre1!=2)return 1;
            else return 0;
        }
        if(dp[i][pre1][pre2]!=-1)return dp[i][pre1][pre2];
        long long ans=0;
        if(pre1==2){
            ans+=solve(i+1,nums[i]%2,pre2,nums,dp);
        }
        else if(pre2==2){
             ans+=solve(i+1,pre1,nums[i]%2,nums,dp);
        }
       else if((pre1==pre2&&nums[i]%2!=pre1)||(pre1!=pre2)){
            ans+=solve(i+1,pre2,nums[i]%2,nums,dp);
        }
        ans+=solve(i+1,pre1,pre2,nums,dp);
        return dp[i][pre1][pre2] = ans%MOD;
    }
};