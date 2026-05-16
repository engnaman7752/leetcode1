class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        return solve(0,n-1,nums);
    }
    int solve(int i,int j,vector<int>&nums){
        if(i==j)return nums[i];
        if(nums[i]<nums[j])return nums[i];
        int mid=i+(j-i)/2;
        return min(solve(i,mid,nums),solve(mid+1,j,nums));
    }
};