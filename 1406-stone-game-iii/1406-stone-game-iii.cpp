class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>dp(n,1e9);
        int ans=solve(0,stoneValue,dp);
        if(ans>0){
            return "Alice";
        }
        else if(ans<0){
            return "Bob";
        }
        else return "Tie";
    }
    int solve(int i,vector<int>&stoneValue,vector<int>&dp){
        int n=dp.size();
        if(i==n)return 0;
        if(dp[i]!=1e9)return dp[i];
        int a=stoneValue[i]-solve(i+1,stoneValue,dp);
        int b=INT_MIN;
        int c=INT_MIN;
        if(i+1<n)
        b=stoneValue[i]+stoneValue[i+1]-solve(i+2,stoneValue,dp);
        if(i+2<n)
        c=stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-solve(i+3,stoneValue,dp);
        return dp[i]=max(a,max(b,c));
    }
};