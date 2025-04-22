class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                cnt++;
                nums[i+1]=nums[i];
            }
        }
    return n-cnt;
        
    }
};