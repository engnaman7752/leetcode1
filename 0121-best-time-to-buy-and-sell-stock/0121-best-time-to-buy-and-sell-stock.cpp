class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int curr=nums[0];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,nums[i]-curr);
            curr=min(curr,nums[i]);
        }
        return ans;
    }
};