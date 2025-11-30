class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        vector<long long> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + nums[i];
        }
        long long total = pre[n-1];
        int rem = total % p;
        if (rem == 0) return 0;
        unordered_map<int, int> mp;
        mp[0] = -1; 
        int ans = n;
        for (int i = 0; i < n; i++) {
            int cur = pre[i] % p;
            int need = (cur - rem + p) % p;     
            if (mp.count(need)) {
                ans = min(ans, i - mp[need]);
            }
            mp[cur] = i;
        }

        return ans == n ? -1 : ans;
    }
};
