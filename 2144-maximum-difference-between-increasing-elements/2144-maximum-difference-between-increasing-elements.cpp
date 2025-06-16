class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
               ans= max(nums[j]-nums[i],ans);
            }
        }
        if(ans<=0)
        return -1;
        else
        return ans;
    }
};