class Solution {
public:
vector<int>p;
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        p=prices;
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(3,vector<long long>(k+1,-1e18)));
        return solve(0,0,k,dp);
    }
    long long solve(int index,int status,int k,vector<vector<vector<long long>>>&dp){
        int n=p.size();
        if(index==n){
            if(status==0)return 0;
            else return -1e18;
        }
        if(dp[index][status][k]!=-1e18)return dp[index][status][k];
        long long skip=solve(index+1,status,k,dp);
        long long buy=-1e18;long long sell=-1e18;
        if(status==0){
            buy=-p[index]+solve(index+1,1,k,dp);
            sell=p[index]+solve(index+1,2,k,dp);
        }
        if(status==1&&k>0){
            sell=p[index]+solve(index+1,0,k-1,dp);
        }
        if(status==2&&k>0){
            buy=-p[index]+solve(index+1,0,k-1,dp);
        }
        return dp[index][status][k]=max(skip,max(sell,buy));
    }
};