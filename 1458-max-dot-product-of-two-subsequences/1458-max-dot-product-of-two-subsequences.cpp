class Solution {
public:
vector<int>f; vector<int>s;int n;int m;
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
         m=nums2.size();
        f=nums1;
        s=nums2;
        vector<vector<int>>dp(n,vector<int>(m,INT_MIN));
        return solve(0,0,dp);
    }
    int solve(int i,int j,vector<vector<int>>&dp){
        if(i>=n||j>=m)return INT_MIN;
        if(dp[i][j]!=INT_MIN)return dp[i][j];
        int a=(f[i]*s[j]);
        int x=solve(i+1,j+1,dp);
        if(x!=INT_MIN){
            a=max(a,a+x);
        }
        int b=solve(i+1,j+1,dp);
        int c=solve(i+1,j,dp);
        int d=solve(i,j+1,dp);
        return dp[i][j]=max({a,c,d});
    }
};