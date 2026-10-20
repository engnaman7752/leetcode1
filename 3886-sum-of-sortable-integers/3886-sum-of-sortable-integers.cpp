class Solution {
public:
    bool poss(vector<int>& nums, int k) {
        int preMax = -1;
        int n = nums.size();
        for (int i = 0; i < n; i += k) {
            int currMin = nums[i];
            int currMax = nums[i];
            int cnt = 0;
            for (int j = i+1; j < i + k; j++) {
                if (nums[j] < nums[j - 1] ){
                    cnt++;
                    if(nums[i+k-1]>currMin)return false;
                }
                 currMin = min(currMin, nums[j]);
                currMax = max(currMax, nums[j]);
            }
            if (preMax > currMin || cnt > 1)
                return false;
            preMax = currMax;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int ans = 0;
        int i = 1;
        int n = nums.size();
        while (i <= n) {
            if (n % i == 0) {
                if (poss(nums, n / i)) {
                    ans += (n / i);
                }
            }
            i++;
        }
        return ans;
    }
};