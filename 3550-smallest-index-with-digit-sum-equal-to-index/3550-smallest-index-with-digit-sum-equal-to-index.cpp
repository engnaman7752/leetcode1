class Solution {
    int no(int x)
    {
        int ans=0;
        while(x>0)
            {
                ans=ans+x%10;
                x=x/10;
            }
        return ans;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            {
                if(i==no(nums[i]))
                    return i;
            }
        return -1;
    }
};
