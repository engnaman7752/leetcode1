class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans=0;
        map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(auto it:mp){
            char c=it.first;
            if(it.second>=2){
                int first=-1;
                int last=-1;
                for(int i=0;i<n;i++){
                    if(s[i]==c)
                   { first=i;
                    break;}
                }
                for(int i=n-1;i>=0;i--){
                    if(s[i]==c)
                   { last=i;
                    break;}
                }
                unordered_set<char>st(s.begin()+first+1,s.begin()+last);
                ans+=st.size();
                }
            }
        
        return ans;
    }
};