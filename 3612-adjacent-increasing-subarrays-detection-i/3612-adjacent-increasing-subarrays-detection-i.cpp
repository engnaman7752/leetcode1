class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return true;
        vector<bool> dp(n, false);      
        for (int i = 0; i <= n - k; i++) {  
            bool flag = true;
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] <= nums[j - 1]) {
                    flag = false;
                    break;
                }
            }
            dp[i] = flag;
        }
        for (int i = 0; i + k < n; i++) {   
            if (dp[i] && dp[i + k]) return true;
        }

        return false;
    }
};
