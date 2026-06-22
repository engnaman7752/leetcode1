class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>mp;
        map<char,int>tx;
        for(auto i:text){
            tx[i]++;
        }
        string t="balloon";
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