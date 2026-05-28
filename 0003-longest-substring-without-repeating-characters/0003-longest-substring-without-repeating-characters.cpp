class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int ans=0;
        map<char,int>mp;
        int n=s.size();
        for(int right=0;right<n;right++){
            if(mp.find(s[right])!=mp.end()){
                if(mp[s[right]]>=left){
                    left=mp[s[right]]+1;
                }
            }
            mp[s[right]]=right;
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};