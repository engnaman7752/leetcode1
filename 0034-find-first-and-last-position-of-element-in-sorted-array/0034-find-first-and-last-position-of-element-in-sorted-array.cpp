class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int index=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(index==nums.size()|| nums[index]!=target)return {-1,-1};
        int last=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        return {index,last-1};
    }
};