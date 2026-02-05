class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[i]=nums[(nums[i]+i)%n];
            }
            else if(nums[i]<0){
                if(nums[i]+i>=0)
                ans[i]=nums[i+nums[i]];
                else{
                ans[i]=nums[(n+((nums[i]+i)%n))%n];
                }
            }
            else{
                ans[i]=nums[i];
            }
        }
        return ans;
    }
};