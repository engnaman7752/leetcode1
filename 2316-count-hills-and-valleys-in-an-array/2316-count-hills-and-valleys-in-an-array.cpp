class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=1;i<nums.size()-1;){

            int next = i + 1;
            while (next < n && nums[next] == nums[i]) ++next;

            if (next < n) {
                if ((nums[i] > nums[i-1] && nums[i] > nums[next]) ||
                    (nums[i] < nums[i-1] && nums[i] < nums[next])) {
                    ++count;
                }
               

        }
         i=next;}
        return count;
    }
};