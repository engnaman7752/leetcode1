class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int nt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                nt++;
                if(nt>1)ans+='(';
                }
            else{
                nt--;
                if(nt>=1)ans+=')';
            }
        }
        return ans;
    }
};