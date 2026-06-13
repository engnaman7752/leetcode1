class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        vector<char>v(26);
        for(int i=0;i<26;i++){
            v[i]='z'-i;
        }
        for(auto s:words){
            int sum=0;
            for(auto c:s){
                int index=c-'a';
                sum+=weights[index];
            }
            ans.push_back(v[sum%26]);
        }
        return ans;
    }
};