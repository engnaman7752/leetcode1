class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int para=0;
        for(int i=n-1;i>=2;i--){
            int start=i-2;
            int end=i-1;

            if(nums[i]<(nums[start]+nums[end]))
                {para=max((nums[i]+nums[start]+nums[end]),para);
                }

        }
        return para;
    }
};