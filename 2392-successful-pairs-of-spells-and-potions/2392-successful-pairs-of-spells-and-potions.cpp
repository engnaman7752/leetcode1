class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());
        vector<int>ans;
        int m = potions.size();
        for (int i = 0; i < spells.size(); i++) {
            long long num = (success + spells[i] - 1) / spells[i];
            auto it = lower_bound(potions.begin(), potions.end(), num);
            ans.push_back(m - (it - potions.begin()));
        }
        return ans;}
    };