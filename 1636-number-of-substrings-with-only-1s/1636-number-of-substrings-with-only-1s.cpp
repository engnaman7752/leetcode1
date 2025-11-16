class Solution {
public:
    int numSub(string s) {
        long long mod=1e9+7;
        long long ans=0;
        long long cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')cnt++;
            else 
           { 
            ans+=(((cnt)*(cnt+1))/2)%mod;
            cnt=0;}
            if(i==s.size()-1&&s[s.size()-1]!='0'){
                 ans+=(((cnt)*(cnt+1))/2)%mod;
            }
        }
        return ans%mod;
    }
};