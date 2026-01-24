class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start=0;
        int end=nums.size()-1;
        int ans=0;
        while(start<end){
            ans=max(nums[start]+nums[end],ans);
            start++;
            end--;
        }
        return ans;
    }
};