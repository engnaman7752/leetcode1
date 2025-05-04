class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>, int> mp;
        for (auto& d : dominoes) {
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            mp[{a, b}]++;
        }
        
        int count = 0;
        for (auto it : mp) {
           int freq=it.second;
            count += (freq * (freq - 1)) / 2;
        }
        return count;
    }
};
