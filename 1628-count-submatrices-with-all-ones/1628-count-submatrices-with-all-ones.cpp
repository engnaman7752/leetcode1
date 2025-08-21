class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(m));
        for(int i=0;i<m;i++)dp[0][i]=mat[0][i];
        for(int i=1;i<n;i++){
          for(int j=0;j<m;j++){
            if(mat[i][j]!=0)
            dp[i][j]=dp[i-1][j]+mat[i][j];
          }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               int minn=dp[i][j];
                for(int k=j;k<m;k++){
                    minn=min(minn,dp[i][k]);
                    ans+=minn;
                }
            }
        }
        return ans;
    }
};