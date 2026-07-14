class Solution {
public:
int mod=1e9+7;
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(201,vector<long long>(201,-1)));
        return solve(0,0,0,dp,nums)-1;
    }
    long long solve(int i,int g1,int g2,vector<vector<vector<long long>>>&dp,vector<int>&nums){
        int n=nums.size();
        if(i==n){
            if(g1==g2)return 1;
            else return 0;
        }
        if(dp[i][g1][g2]!=-1)return dp[i][g1][g2];
        long long ans=0;
        ans+=solve(i+1,g1,g2,dp,nums)%mod;
        ans+=solve(i+1,gcd(g1,nums[i]),g2,dp,nums)%mod;
        ans+=solve(i+1,g1,gcd(g2,nums[i]),dp,nums)%mod;
        return dp[i][g1][g2]=ans%mod;
    }
};