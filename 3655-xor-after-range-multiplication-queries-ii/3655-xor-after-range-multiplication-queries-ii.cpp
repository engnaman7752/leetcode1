class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    long long inv(long long x) {
        return power(x, MOD - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n);

        // (k, remainder) → queries
        map<pair<int,int>, vector<vector<int>>> mp;

        // Step 1: split queries
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2];

            if (k <= B) {
                mp[{k, l % k}].push_back(q);
            } else {
                // brute force
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * q[3]) % MOD;
                }
            }
        }

        // Step 2: process small k groups
        for (auto &[key, vec] : mp) {
            int k = key.first;
            int rem = key.second;

            int len = (n - rem + k - 1) / k;   // size of this bucket
            vector<long long> diff(len + 1, 1);

            for (auto &q : vec) {
                int l = q[0], r = q[1];
                long long v = q[3];

                // 🔥 ALIGN l to this remainder
                int first = l;
                if (first % k != rem) {
                    first += (rem - first % k + k) % k;
                }

                if (first > r) continue;

                int L = (first - rem) / k;
                int R = (r - rem) / k;

                diff[L] = diff[L] * v % MOD;
                if (R + 1 < diff.size()) {
                    diff[R + 1] = diff[R + 1] * inv(v) % MOD;
                }
            }

            // prefix multiplication and apply
            long long cur = 1;
            for (int i = 0; i < len; i++) {
                cur = cur * diff[i] % MOD;
                int idx = rem + i * k;
                if (idx < n) {
                    nums[idx] = nums[idx] * cur % MOD;
                }
            }
        }

        // Step 3: XOR result
        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};