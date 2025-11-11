class Solution {
public:
       vector<pair<int,int>>cnt;
        int s;
    int findMaxForm(vector<string>& strs, int m, int n) {
        s=strs.size();
        for(auto str:strs){
            int zero=count(str.begin(),str.end(),'0');
            int one=count(str.begin(),str.end(),'1');
            cnt.push_back({zero,one});
        }
        vector<vector<vector<int>>>dp(s,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,m,n,dp);
    }
    int solve(int i,int m,int n,vector<vector<vector<int>>>&dp){
        if(m<0||n<0||i>=s)return 0;
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        int skip=solve(i+1,m,n,dp);
        int take=0;
        if(m-cnt[i].first>=0&&n-cnt[i].second>=0){
            take=1+solve(i+1,m-cnt[i].first,n-cnt[i].second,dp);
        }
        return dp[i][m][n]=max(skip,take);
    }
};