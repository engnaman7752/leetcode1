class Solution {
    void solve(int n,int open,int close,string &s,vector<string>& ans) {
        if (open == n && close == n) {
           
                ans.push_back(s);
                return;
        }
        if (open < n) {
            s.push_back('(');
            open++;
            solve(n,open, close, s, ans);
            s.pop_back();
            open--;
        }
        if (close < n && close < open) {
            s.push_back(')');
            close++;
            solve(n,open, close, s, ans);
            s.pop_back();
            close--;
        }
       
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        int open = 0;
        int close = 0;
        solve(n,open, close, s, ans);
        return ans;
    }
};