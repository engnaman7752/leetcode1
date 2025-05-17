class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int first = 0;
        int last = n - 1;
        
        for (int i = 0; i <= last; ) {
            if (nums[i] == 0) {
                swap(nums[i], nums[first]);
                first++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[last]);
                last--;
            } else {
                i++;
            }
        }
    }
};
