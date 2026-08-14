class Solution {
public:
    int maximumLengthSubstring(string nums) {
         int l = 0;
        int n = nums.size();
        int ans = 1;
        map<int, int> mp;
        for (int r = 0; r < n; r++) {
            mp[nums[r]]++;
            while (mp[nums[r]] > 2) {
                mp[nums[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};