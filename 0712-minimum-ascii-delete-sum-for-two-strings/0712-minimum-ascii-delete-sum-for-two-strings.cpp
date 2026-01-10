class Solution {
public:
int n;int m; string a ; string b;
    int minimumDeleteSum(string s1, string s2) {
        n=s1.size();m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        a=s1;
        b=s2;
        return solve(0,0,dp);
    }
    int solve(int i,int j,vector<vector<int>>&dp){
       if (i == n) {
            int cost = 0;
            for (int k = j; k < m; k++) cost += b[k];
            return cost;
        }
        if (j == m) {
            int cost = 0;
            for (int k = i; k < n; k++) cost += a[k];
            return cost;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int e=INT_MAX,k,l,m;
        if(a[i]==b[j]){
            e=solve(i+1,j+1,dp);
        }
        k=a[i]+b[j]+solve(i+1,j+1,dp);
        l=a[i]+solve(i+1,j,dp);
        m=b[j]+solve(i,j+1,dp);
        return dp[i][j]=min({e,k,l,m});
    }
};