class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int prev2,prev=nums[0];
        for(int i=1;i<nums.size();i++)
        {int x=nums[i];
            if(i>1)
            x+=prev2;
        int y=prev;
        prev2=prev;
            prev=max(x,y);
        }
        return prev;
    }
   
};