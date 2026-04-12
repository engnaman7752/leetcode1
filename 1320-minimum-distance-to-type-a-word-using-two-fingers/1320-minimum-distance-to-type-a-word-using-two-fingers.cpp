class Solution {
public:
vector<pair<int,int>> alph = vector<pair<int,int>>(26, {0,0});
int n;
    int minimumDistance(string word) {
        int curr=0;
        n=word.size();
      for (int i = 0; i < 26; i++) {
            alph[i] = {i / 6, i % 6};
        }
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(27,vector<int>(27,-1)));
        return solve(0,-1,-1,word,dp);
    }
    int solve(int i,int f1,int f2,string &word, vector<vector<vector<int>>>&dp){
        if(i==n)return 0;
        if(dp[i][f1+1][f2+1]!=-1)return dp[i][f1+1][f2+1];
         int a;int b;
        if(f1!=-1)
        a=abs((int)(alph[f1].first-alph[word[i]-'A'].first))+abs((int)(alph[f1].second-alph[word[i]-'A'].second));
        if(f2!=-1)
        b=abs((int)(alph[f2].first-alph[word[i]-'A'].first))+abs((int)(alph[f2].second-alph[word[i]-'A'].second));
        if(f1==-1){
            a=0;
        }
        if(f2==-1){
            b=0;
        }
        a+=solve(i+1,(int)word[i]-'A',f2,word,dp);
        b+=solve(i+1,f1,(int)word[i]-'A',word,dp);
        return dp[i][f1+1][f2+1]=min(a,b);
    }
};