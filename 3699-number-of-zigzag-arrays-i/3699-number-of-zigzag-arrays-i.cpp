class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        long long MOD = 1e9 + 7;
        
        // Normalize the range to [0, m] to save space and simplify indexing
        int m = r - l;
        
        // dp[v] represents the number of valid patterns ending with value v
        vector<int> dp(m + 1, 1);
        
        for (int i = 1; i < n; i++) {
            long long preSum = 0;
            
            if (i % 2 == 1) {
                // Odd length: transition UP (pick a strictly larger element)
                // We overwrite the array in-place using a running prefix sum
                for (int v = 0; v <= m; v++) {
                    long long current_val = dp[v];
                    dp[v] = preSum;
                    preSum = (preSum + current_val) % MOD;
                }
            } else {
                // Even length: transition DOWN (pick a strictly smaller element)
                // We overwrite the array in-place using a running suffix sum
                for (int v = m; v >= 0; v--) {
                    long long current_val = dp[v];
                    dp[v] = preSum;
                    preSum = (preSum + current_val) % MOD;
                }
            }
        }
        
        long long ans = 0;
        for (int v : dp) {
            ans = (ans + v) % MOD;
        }
        
        // Multiply by 2 because every valid "Up-started" array has an exact 
        // mirror "Down-started" array!
        return (ans * 2) % MOD;
    }
};