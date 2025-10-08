class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n,-1);
        unordered_set<string>words(wordDict.begin(),wordDict.end());
        return solve(0,s,dp,words);
    }
    bool solve(int index,string s,vector<int>&dp,unordered_set<string>&words){
        if(index==s.size())return true;
        if(dp[index]!=-1)return dp[index];
        for(int i=index;i<s.size();i++)
          { string temp=s.substr(index,i-index+1);
          if(words.find(temp)!=words.end()&&solve(i+1,s,dp,words))return dp[index]=1;
          } 
          return dp[index]=0;
    }
};