class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
       int ans=0;
       for(int i=0;i<nums.size();i++)
       {
        ans=ans|nums[i];
       }
       ans=ans<<(nums.size()-1);
       return ans;
    }
};