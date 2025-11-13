class Solution {
public:
    int maxOperations(string s) {
        int ans=0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                ans+=cnt;
                while(i<s.size()&&s[i]!='1')i++;
            }
            if(s[i]=='1')cnt++;
        }
        return ans;
    }
};