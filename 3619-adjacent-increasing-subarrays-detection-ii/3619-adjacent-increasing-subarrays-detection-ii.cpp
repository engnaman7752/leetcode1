class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        vector<int> inc; 
        int len = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) len++;
            else {
                inc.push_back(len);
                len = 1;
            }
        }
        inc.push_back(len);

        int ans = 0;
        for (int i = 0; i < inc.size(); i++) {
            int a = inc[i] / 2;
            ans = max(ans, a);
            if (i > 0) ans = max(ans, min(inc[i - 1], inc[i]));
        }
        return ans;
    }
};
