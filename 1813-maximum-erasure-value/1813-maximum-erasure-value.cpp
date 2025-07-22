class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        int left = 0, right = 0, sum = 0, ans = 0;
        
        while (right < nums.size()) {
            while (s.find(nums[right]) != s.end()) {
                s.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
            
            s.insert(nums[right]);
            sum += nums[right];
            ans = max(ans, sum);
            right++;
        }

        return ans;
    }
};
