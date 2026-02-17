class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>v(26,0);int n=s.size();
        int left=0;int ans=0;
        for(int right=0;right<n;right++){
            v[s[right]-'A']++;
            int t=*max_element(v.begin(),v.end());
            if((right-left+1)-t>k){
                v[s[left]-'A']--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};