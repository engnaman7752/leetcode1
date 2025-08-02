class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
          int s=cuts.size();
        vector<vector<int>>dp(s,vector<int>(s,-1));
        return solve(1,s-2,dp,cuts);
        
    }
    int solve(int i,int j,vector<vector<int>>&dp,vector<int>&cuts){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
            ans=min(ans,(cuts[j+1]-cuts[i-1])+(solve(i,k-1,dp,cuts)+solve(k+1,j,dp,cuts)));
        }
        return dp[i][j]=ans;

    }
};