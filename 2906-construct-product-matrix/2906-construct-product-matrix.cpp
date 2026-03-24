class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mod=12345;
        vector<vector<int>>ans(n,vector<int>(m));
        int pre=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=pre%mod;
                pre=((pre%mod)*(grid[i][j]%mod))%mod;
            }
        }
        int post=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                ans[i][j]=((ans[i][j]%mod)*(post%mod))%(mod);
                post=((post%mod)*(grid[i][j]%mod))%mod;
            }
        }
        return ans;
    }
};