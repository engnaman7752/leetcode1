class Solution {
public:
   long long maximumTripletValue(vector<int>& nums) {
        long long max1 = nums[0];  
        long long maxDiff = LLONG_MIN; // max (max1 - nums[j])
        long long ans = 0;

        for (int j = 1; j < nums.size(); j++) {
            if (j >= 2) {
                ans = max(ans, maxDiff * nums[j]);
            }
            maxDiff = max(maxDiff, max1 - nums[j]);
            max1 = max(max1, (long long)nums[j]);
        }
        return ans;
    }
};