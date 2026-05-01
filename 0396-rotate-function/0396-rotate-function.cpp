class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f=0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            f+=(i*nums[i]);
            sum+=nums[i];
        }
        int ans=f;
        for(int i=n-1;i>0;i--){
            f+=sum-n*nums[i];
            ans=max(ans,f);
        }
        return ans;
    }
};