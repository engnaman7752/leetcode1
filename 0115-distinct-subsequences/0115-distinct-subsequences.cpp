class Solution {
public:
    int numDistinct(string s, string t) {
       int n=s.size();
       int m=t.size();
       vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,s,t,dp);
        
    }
    int solve(int index1,int index2,string &s,string &t,vector<vector<int>>& dp){
        if(index2==t.size())return 1;
        if(index1==s.size())return 0;
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        int count=0;
        if(s[index1]==t[index2]){
            count+=solve(index1+1,index2+1,s,t,dp);
        }
        count+=solve(index1+1,index2,s,t,dp);
        return dp[index1][index2]=count;
    }
};