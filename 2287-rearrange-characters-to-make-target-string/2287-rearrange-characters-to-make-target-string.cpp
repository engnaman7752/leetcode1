class Solution {
public:
    int rearrangeCharacters(string text, string t) {
        map<char,int>mp;
        map<char,int>tx;
        for(auto i:text){
            tx[i]++;
        }
        for(auto i:t){
            mp[i]++;
        }
        int ans=INT_MAX;
        for(auto i:t){
            ans=min(ans,tx[i]/mp[i]);
        }
        return ans;
    }
};