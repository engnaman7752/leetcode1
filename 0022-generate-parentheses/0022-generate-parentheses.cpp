class Solution {
public:
    void solve(int n,string &s,vector<string>&ans,int open ,int close){
        if(open==n && close==n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s+='(';
            solve(n,s,ans,open+1,close);
            s.pop_back();
        }
        if( open>close){
            s+=')';
            solve(n,s,ans,open,close+1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string >ans;
        string s="";
        solve(n,s,ans,0,0);
        return ans;
    }
};