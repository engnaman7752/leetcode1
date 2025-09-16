class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int ans=0;
        int l=0;
        int r=0;
        while(r<s.size()){
            if(mp.find(s[r])!=mp.end()){
                l=max(l,mp[s[r]]+1);
            }
            ans=max(ans,(r-l+1));
            mp[s[r]]=r;
            r++;
             
        }
        return ans;
    }
};