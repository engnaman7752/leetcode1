class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();int ans=1;
        for(int i=0;i<n;i++){
            map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if((j-i+1)/mp.size()==mp[s[j]]){
                   bool flag=true;
                    for(auto [ch,freq]:mp){
                        if(freq!=mp[s[j]]){
                            flag=false;
                            break;
                        }
                    }
                    if(flag)ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};