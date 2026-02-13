class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=0;  int run = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i] == s[i-1]) run++;
            else run = 1;
            ans = max(ans, run);
        }
       ans=max(ans,solve('a','b',s));
       ans=max(ans,solve('a','c',s));
       ans=max(ans,solve('b','c',s));
       map<pair<int,int>,int>mp;
       mp[{0,0}]=-1;
       int cnta=0;int cntb=0;int cntc=0;
       for(int i=0;i<n;i++){
        if(s[i]=='a')cnta++;
        else if(s[i]=='b')cntb++;
        else cntc++;
        if(mp.find({cntb-cnta,cntc-cnta})!=mp.end())ans=max(ans,i-mp[{cntb-cnta,cntc-cnta}]);
        else
        mp[{cntb-cnta,cntc-cnta}]=i;
       }
        return ans;
    }
    int solve(char a,char b,string &s){
        int n=s.size(); map<int,int>mp;int ans=0;int cnta=0;int cntb=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            if(s[i]==a)cnta++;
            else if(s[i]==b)cntb++;
            else{
              mp.clear();cnta=0;cntb=0;mp[0]=i;continue;
            }
            if(mp.find(cnta-cntb)!=mp.end())ans=max(ans,i-mp[cnta-cntb]);
            else
            mp[cnta-cntb]=i;
        }
        return ans;
    }
};