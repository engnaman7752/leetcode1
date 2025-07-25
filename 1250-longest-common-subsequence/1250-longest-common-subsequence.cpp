class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,text1,text2,dp);
        
    }
    int solve(int ind1,int ind2,string &s1,string &s2,vector<vector<int>>&dp){
        int n=s1.size();
        int m=s2.size();
        if(ind1<0||ind2<0||ind1>=n||ind2>=m)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2])return dp[ind1][ind2]=1+solve(ind1+1,ind2+1,s1,s2,dp);
        else
        return dp[ind1][ind2]=max(solve(ind1+1,ind2,s1,s2,dp),solve(ind1,ind2+1,s1,s2,dp));


    }
};