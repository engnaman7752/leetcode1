class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> t(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] % modulo == k)
                cnt++;
            t[i] = cnt;
        }

        map<int, long long> mp;
        long long result = 0;
        mp[0] = 1;

        for (int i = 0; i < n; i++) {
            int sum = t[i] % modulo;
            int target = (sum - k + modulo) % modulo;
            result += mp[target];
            mp[sum]++;
        }

        return result;
    }
};
