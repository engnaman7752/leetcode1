class Solution {
    int cnt(int no)
    {
        int ans=0;
        while(no>0)
        {
            ans=ans+no%10;
            no=no/10;
        }
        return ans;
    }
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,cnt(nums[i]));

        }
        return ans;
        
    }
};