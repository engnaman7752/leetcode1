class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left=0;
        int right=0;
        int n=nums.size();
        int ans=1;
        while(right<n){
            while(nums[right]>(long long)nums[left]*k)left++;
            ans=max(ans,right-left+1);
            right++;
        }
        return n-ans;
    }
};