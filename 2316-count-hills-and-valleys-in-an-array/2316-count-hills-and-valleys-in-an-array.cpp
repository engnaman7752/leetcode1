class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=1;i<nums.size()-1;i++){
            if (nums[i] == nums[i - 1]) continue;

            int prev = i - 1;
            while (prev >= 0 && nums[prev] == nums[i]) --prev;

            int next = i + 1;
            while (next < n && nums[next] == nums[i]) ++next;

            if (prev >= 0 && next < n) {
                if ((nums[i] > nums[prev] && nums[i] > nums[next]) ||
                    (nums[i] < nums[prev] && nums[i] < nums[next])) {
                    ++count;
                }

        }}
        return count;
    }
};