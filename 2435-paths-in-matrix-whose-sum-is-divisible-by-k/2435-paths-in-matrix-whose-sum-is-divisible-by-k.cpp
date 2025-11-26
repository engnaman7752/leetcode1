class Solution {
public:
vector<vector<int>>mat;
int mod;
int MOD=1e9+7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        mat=grid;
        mod=k;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        return solve(0,0,0,dp);
    }
int solve(int i,int j,int rem,vector<vector<vector<int>>>&dp){
    int n=mat.size();
    int m=mat[0].size();
    if(i==n-1&&j==m-1){
        if((mat[i][j]+rem)%mod==0)return 1;
        else return 0;
    }
    if(i>=n||j>=m)return 0;
    if(dp[i][j][rem]!=-1)return dp[i][j][rem];
    long long right=solve(i+1,j,(rem+mat[i][j])%mod,dp);
    long long down=solve(i,j+1,(rem+mat[i][j])%mod,dp);
    return dp[i][j][rem]=(right+down)%MOD;
}
};