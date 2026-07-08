class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        
        vector<long long> pow10(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; ++i) {
            pow10[i] = (1LL * pow10[i - 1] * 10) % mod;
        }
        
        vector<long long> sum(n + 1, 0);
        vector<long long> digit(n + 1, 0);
        vector<int> nz_count(n + 1, 0);
        
        for(int i = 0; i < n; i++) {
            int d = s[i] - '0';
            sum[i+1] = sum[i] + d;
            if (d != 0) {
                digit[i+1] = (1LL * digit[i] * 10 + d) % mod;
                nz_count[i+1] = nz_count[i] + 1;
            } else {
                digit[i+1] = digit[i];
                nz_count[i+1] = nz_count[i];
            }
        }
        
        int m = queries.size();
        vector<int> ans;
        for(int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int sm = sum[r+1] - sum[l];
            int len = nz_count[r+1] - nz_count[l];
            int di = (digit[r+1] - (1LL * digit[l] * pow10[len]) % mod + mod) % mod;
            
            ans.push_back((1LL * sm * di) % mod);
        }
        
        return ans;
    }
};