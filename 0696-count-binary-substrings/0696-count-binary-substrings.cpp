class Solution {
public:
    int countBinarySubstrings(string s) {
       int pre=0;
       int cnt=1;int n=s.size();int ans=0;
       for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                ans+=min(pre,cnt);
                pre=cnt;
                cnt=1;
            }
            else{
                cnt++;
            }
       }
       ans+=min(pre,cnt);
       return ans; 
    }
};