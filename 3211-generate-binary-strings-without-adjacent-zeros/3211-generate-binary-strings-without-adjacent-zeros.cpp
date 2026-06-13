class Solution {
public:
int n;
    void solve(int i, string &s,vector<string>&ans){
        if(i==n){
            ans.push_back(s);
            return ;
        }
        if(i==0 || s[i-1]=='1'){
            s+='0';
            solve(i+1,s,ans);
            s.pop_back();
        }
            s+='1';
            solve(i+1,s,ans);
            s.pop_back();
    }
    vector<string> validStrings(int _n) {
        n=_n;
        vector<string>ans;
        string s="";
        solve(0,s,ans);
        return ans;
    }
};