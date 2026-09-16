class Solution {
public:
int mod=1e9+7;
    int numberOfSets(int n, int k) {
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return solve(0,k,n,dp,0)%mod;
    }
    int solve(int i,int k,int n,vector<vector<vector<int>>>&dp,int flag){
        if(k==0)return 1;
        if(i>=n)return 0;
        if(dp[i][k][flag]!=-1)return dp[i][k][flag];
        long long a=0;
        if(flag){
            a+=solve(i,k-1,n,dp,0)%mod;
            a+=solve(i+1,k,n,dp,1)%mod;
        }
        else{
            a+=solve(i+1,k,n,dp,1)%mod;
            a+=solve(i+1,k,n,dp,0)%mod;
        }
        return dp[i][k][flag]=a%mod;
    }
};