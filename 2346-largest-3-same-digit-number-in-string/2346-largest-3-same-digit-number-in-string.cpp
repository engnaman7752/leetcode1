class Solution {
public:
    string largestGoodInteger(string s) {
        string ans;
        int n=s.size();
        for(int i=0;i<n-2;i++){
            if(s[i]==s[i+1]&&s[i+1]==s[i+2]){
                if(ans.empty()||ans[0]<s[i]){
                    ans=s.substr(i,3);
                }
            }
        }
       return ans; 
    }
};