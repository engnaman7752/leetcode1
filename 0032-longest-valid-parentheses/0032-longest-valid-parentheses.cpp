class Solution {
public:
    int longestValidParentheses(string s) {
        // int start=0;
        // int end=s.size()-1;
        // return solve(start,end,s);
        stack<int>st;
        st.push(-1);
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')st.push(i);
            else{
                st.pop();
                if(!st.empty()){
                    ans=max(ans,i-st.top());
                   // st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }
        return ans;
    }
    int solve(int start,int end,string &s){
        if(start>=end)return 0;
        int open=0;
        int close=0;
        int ans=0;
        for(int i=start;i<=end;i++){
            if(s[i]=='(')open++;
            else close++;
            if(close>open){
                return max(solve(start,i-1,s),solve(i+1,end,s));
            }
            if(open==close)ans=i-start+1;
        }
        return ans;
    }
};