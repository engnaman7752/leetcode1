class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       return solve(0,0,dp,s,p);
        
    }
    bool solve(int ind1,int ind2,vector<vector<int>>& dp, string s, string p){
        int n=s.size();
        int m=p.size();
        if(ind2==m)return ind1==n;
        if(ind1==n){  for (int k = ind2; k < m; ++k)
                if (p[k] != '*') return false;
            return true;}
        
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(s[ind1]==p[ind2]||p[ind2]=='?') return dp[ind1][ind2]=solve(ind1+1,ind2+1,dp,s,p);
        if(p[ind2]=='*')return dp[ind1][ind2]=(solve(ind1,ind2+1,dp,s,p)||solve(ind1+1,ind2,dp,s,p));
        
        else return dp[ind1][ind2]=false;

    }
};