class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9+7;
        vector<long long> powers;
      
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                powers.push_back(1LL << i);
            }
        }

      
        vector<long long> prefix(powers.size());
        prefix[0] = powers[0] % MOD;
        for (int i = 1; i < powers.size(); i++) {
            prefix[i] = (prefix[i-1] * powers[i]) % MOD;
        }

        
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            if (l == 0) {
                ans.push_back(prefix[r]);
            } else {
                long long num = prefix[r];
                long long den = prefix[l-1];
                long long inv = modPow(den, MOD-2, MOD);
                ans.push_back((num * inv) % MOD);
            }
        }
        return ans;
    }

    long long modPow(long long a, long long b, long long mod) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
};
