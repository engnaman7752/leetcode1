class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,word1,word2,dp);
    }
    int solve(int ind1,int ind2,string & word1,string & word2,vector<vector<int>>&dp){
        int n=word1.size();
        int m=word2.size();
        if(ind2==m)return n-ind1;
        if(ind1==n)return m-ind2;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(word1[ind1]==word2[ind2])return dp[ind1][ind2]= solve(ind1+1,ind2+1,word1,word2,dp);
        else
        return dp[ind1][ind2]=1+min(solve(ind1+1,ind2+1,word1,word2,dp),min(solve(ind1+1,ind2,word1,word2,dp),solve(ind1,ind2+1,word1,word2,dp)));


    }

};