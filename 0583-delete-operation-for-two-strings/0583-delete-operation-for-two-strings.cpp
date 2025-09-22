class Solution {
    int solve(int i,int j,string s1,string s2,vector<vector<int>>&dp){
       int n=s1.size();
        int m=s2.size();
        if(i==n){
            if(j==m)return 0;
            else return m-j;
        }
        if(j==m){
            if(i==n)return 0;
            else return n-i;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j]=solve(i+1,j+1,s1,s2,dp);
        else{
            return dp[i][j]=1+min(solve(i+1,j,s1,s2,dp),solve(i,j+1,s1,s2,dp));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,word1,word2,dp);
    }
};