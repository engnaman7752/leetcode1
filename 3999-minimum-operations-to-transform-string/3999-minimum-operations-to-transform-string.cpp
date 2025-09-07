class Solution {
public:
    int minOperations(string sa) {
        set<char>st(sa.begin(),sa.end());
        string s(st.begin(),st.end());
        sort(s.begin(),s.end());
        int n=s.size();
        int ans=0;
        char pre='z';
        for(int i=n-1;i>=0;i--){
              if(s[i]=='a')break;
            ans+=(int)(pre-s[i]);
            pre=s[i];
        }
        if(s.size()==1&&s[0]=='a')return 0;
        return ans+1;
    }
};