class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {int x=nums[i];
            if(i>1)
            x+=dp[i-2];
        int y=dp[i-1];
            dp[i]=max(x,y);
        }
        return dp[nums.size()-1];
    }
   
};