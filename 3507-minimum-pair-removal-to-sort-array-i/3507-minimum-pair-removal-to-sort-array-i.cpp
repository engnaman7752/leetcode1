class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        while (!isSorted(nums)) {
            int index = 0, minSum = nums[0] + nums[1];
            for (int i = 1; i < nums.size() - 1; i++) {
                int s = nums[i] + nums[i + 1];
                if (s < minSum) {
                    minSum = s;
                    index = i;
                }
            }
            vector<int> arr;
            for (int i = 0; i < index; i++) arr.push_back(nums[i]);
            arr.push_back(nums[index] + nums[index + 1]);
            for (int i = index + 2; i < nums.size(); i++) arr.push_back(nums[i]);
            nums = arr;
            count++;
        }
        return count;
    }
    
    bool isSorted(const vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
};
