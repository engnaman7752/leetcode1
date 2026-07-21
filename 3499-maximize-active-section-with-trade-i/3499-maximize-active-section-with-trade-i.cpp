class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        vector<int>pre(n,0);
        if(s[0]=='1')pre[0]=1;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+s[i]-'0';
        }
        int ans=pre[n-1];
        int left=0;
        bool zero=false;
        bool one=false;
        while(s[left]=='1')left++;
        for(int right=left;right<n;right++){
            if((s[right]=='1' && zero && one)){
                while(s[left]!='1')left++;
                while(s[left]!='0')left++;
                zero=false;
                one=false;
            }
            if(s[right]=='1')one=true;
            if(one && s[right]=='0')zero=true;
            if(one && zero) ans=max(ans,right-left+1+(left!=0?pre[left-1]:0)+pre[n-1]-pre[right]);
        }
        return ans;
    }
};