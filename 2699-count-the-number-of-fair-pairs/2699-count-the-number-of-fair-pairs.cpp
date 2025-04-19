class Solution {
private:
    int lowerBound(int index, vector<int>& nums, int lower) {
        int start = 0, end = index - 1, res = index;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] + nums[index] >= lower) {
                res = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return res;
    }

    int upperBound(int index, vector<int>& nums, int upper) {
        int start = 0, end = index - 1, res = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] + nums[index] <= upper) {
                res = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return res;
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            int l = lowerBound(i, nums, lower);
            int h = upperBound(i, nums, upper);
            if (h >= l) ans += (h - l + 1);
        }
        return ans;
    }
};
