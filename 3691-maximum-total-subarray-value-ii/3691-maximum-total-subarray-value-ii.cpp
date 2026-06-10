#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        
        // ==========================================
        // 1. BUILD THE SPARSE TABLES
        // ==========================================
        // Find the maximum power of 2 needed to cover 'n' elements
        int logn = 32 - __builtin_clz(n); 
        
        vector<vector<int>> stMax(n, vector<int>(logn));
        vector<vector<int>> stMin(n, vector<int>(logn));

        // Base case: intervals of length 1 (2^0). Just the elements themselves.
        for (int i = 0; i < n; i++) {
            stMax[i][0] = stMin[i][0] = nums[i];
        }

        // Build the table using the "combining halves" trick
        for (int j = 1; j < logn; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                // max/min of the first half AND the second half
                stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
                stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
            }
        }

        // ==========================================
        // 2. THE O(1) "OVERLAP" QUERY FUNCTIONS
        // ==========================================
        auto queryMax = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1); // Largest power of 2 that fits inside (r - l + 1)
            // Compare the overlapping left chunk and right chunk
            return max(stMax[l][j], stMax[r - (1 << j) + 1][j]);
        };

        auto queryMin = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return min(stMin[l][j], stMin[r - (1 << j) + 1][j]);
        };

        // ==========================================
        // 3. PRIORITY QUEUE STRATEGY
        // ==========================================
        // Stores tuples of: {subarray_score, left_index, right_index}
        priority_queue<tuple<long long, int, int>> pq;

        // Initialize by pushing the absolute best subarray for EVERY starting index 'l'
        for (int l = 0; l < n; l++) {
            long long score = (long long)queryMax(l, n - 1) - queryMin(l, n - 1);
            pq.emplace(score, l, n - 1);
        }

        long long ans = 0;
        
        // 4. Extract the absolute best subarray exactly 'k' times
        while (k-- > 0 && !pq.empty()) {
            auto [val, l, r] = pq.top();
            pq.pop();
            
            ans += val; // Add the best available subarray score to our total
            
            // Since we just used the subarray [l...r], the next best subarray 
            // starting at 'l' is [l...r-1]. Let's calculate its score and push it!
            if (r > l) {
                long long nextScore = (long long)queryMax(l, r - 1) - queryMin(l, r - 1);
                pq.emplace(nextScore, l, r - 1);
            }
        }

        return ans;
    }
};