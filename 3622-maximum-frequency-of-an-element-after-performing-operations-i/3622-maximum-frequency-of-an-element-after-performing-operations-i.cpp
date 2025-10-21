class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (int x : nums) mp[x]++;

        int ans = 0;
        int mn = nums.front(), mx = nums.back();
        for (int val = mn; val <= mx; ++val) {
            int a = lower_bound(nums.begin(), nums.end(), val - k) - nums.begin();
            int b = upper_bound(nums.begin(), nums.end(), val + k) - nums.begin();
            int total = b - a;
            int cnt = mp.count(val) ? mp[val] : 0;
            ans = max(ans, min(total, cnt + numOperations));
        }

        return ans;
    }
};
