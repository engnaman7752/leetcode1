class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int ans = INT_MAX;
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            string t = to_string(nums[i]);
            reverse(t.begin(), t.end());
            int rev = stoi(t);
            if (mp.count(nums[i])) {
                ans = min(ans, i - mp[nums[i]]);
            }
            mp[rev]=i;
            
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};