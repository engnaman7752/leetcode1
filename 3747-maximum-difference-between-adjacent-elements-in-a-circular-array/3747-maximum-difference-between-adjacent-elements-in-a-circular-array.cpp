class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {if(i==n-1)
            ans=max(ans,abs(nums[i]-nums[0]));
        else
            ans=max(ans,abs(nums[i]-nums[i+1]));
        }
        return ans;
    }
};