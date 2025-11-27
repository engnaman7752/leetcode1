class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n, 0);
        pre[0] = nums[0];

        for(int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];

        vector<long long> kSum(k, LLONG_MAX / 2); 
        kSum[k - 1] = 0; 
        long long ans = LLONG_MIN;
        for(int i = 0; i < n; i++){
            ans = max(ans, pre[i] - kSum[i % k]);
            kSum[i % k] = min(kSum[i % k], pre[i]);
        }
        return ans;
    }
};
