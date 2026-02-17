class Solution {
public:
    bool isVowel(char c){
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    int maxVowels(string s, int k) {
        int cnt=0;int ans=0;
        int left=0;int n=s.size();
        for(int right=0;right<n;right++){
            if(isVowel(s[right]))cnt++;
            if(right-left+1>k){
                if(isVowel(s[left]))cnt--;
                left++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};