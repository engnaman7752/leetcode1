class Solution {
public:
    set<string>st;
    vector<string> removeInvalidParentheses(string s) {
        int need=0;
        int open=0;
        for(char ch:s){
            if(ch=='('){
                open++;
            }
            else if(ch==')')open--;
            if(open<0){
                need++;
                open=0;
            }
        }
        need+=open;
        //cout<<need<<endl;
        string t="";
        solve(0,0,t,s,need);
        if(st.empty())return {""};
        vector<string>ans(st.begin(),st.end());
        return ans;
    }
    void solve(int i,int open,string &t,string &s,int need){
        int n=s.size();
        if(open<0 || need<0)return;
        if(i==n){
            if(need==0 && open==0)st.insert(t);
            return;
        }
        int curr=open;
        if(s[i]=='(')curr++;
        else if(s[i]==')')curr--;
        t+=s[i];
        solve(i+1,curr,t,s,need);
        t.pop_back();
        solve(i+1,open,t,s,need-1);

    }
};