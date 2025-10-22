class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        unordered_map<long long, long long> mp;
        for (long long x : nums) mp[x]++;

        long long n = nums.size();
        long long ans = 0;

        for (long long i = 0; i < n; ++i) {
            vector<long long> targets = {nums[i], nums[i] + k, nums[i] - k};

            for (long long val : targets) {
                long long a = lower_bound(nums.begin(), nums.end(), val - k) - nums.begin();
                long long b = upper_bound(nums.begin(), nums.end(), val + k) - nums.begin();
                long long total = b - a;
                long long cnt = mp.count(val) ? mp[val] : 0;
                ans = max(ans, min(total, cnt + numOperations));
            }
        }

        return ans;
    }
};
