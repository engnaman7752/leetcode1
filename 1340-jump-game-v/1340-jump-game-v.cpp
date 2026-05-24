class Solution {
public:
    int solve(int i, vector<int>& arr, int d, vector<int>& dp) {
    
        if (dp[i] != -1) return dp[i];

        // 2. Base case: you can always visit at least 1 index (the starting one)
        int max_path = 1; 

        // 3. Jump Right
        for (int j = 1; j <= d && i + j < arr.size(); ++j) {
            if (arr[i] <= arr[i + j]) break; // Blocked!
            max_path = max(max_path, 1 + solve(i + j, arr, d, dp));
        }

        // 4. Jump Left
        for (int j = 1; j <= d && i - j >= 0; ++j) {
            if (arr[i] <= arr[i - j]) break; // Blocked!
            max_path = max(max_path, 1 + solve(i - j, arr, d, dp));
        }

        return dp[i] = max_path;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1); 
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, arr, d, dp));
        }
        
        return ans;
    }
};