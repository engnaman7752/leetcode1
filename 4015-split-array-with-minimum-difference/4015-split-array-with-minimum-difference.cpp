class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long leftSum=0;
        long long rightSum=0;
        int left=0;
        int right=0;
        int n=nums.size();
        if(n==2)return abs(nums[0]-nums[1]);
        while(left<n-1&&nums[left]<nums[left+1]){leftSum+=nums[left];left++;}
        right=left+1;
        while(right<n-1){
            if(nums[right]<=nums[right+1])return -1;
            rightSum+=nums[right];
            right++;
        }
        rightSum+=nums[right];
        if(rightSum>leftSum||nums[left]==nums[left+1])leftSum+=nums[left];
        else rightSum+=nums[left];
        return abs(rightSum-leftSum);

    }
};