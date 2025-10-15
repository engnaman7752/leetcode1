class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int c1=1;int c2=1;
        int i=1;
        while(i<n&&nums[i]>nums[i-1]){
            i++;
            c1++;
        }
       int ans=0;
       i++;
       while(i<n){
        if(nums[i]<=nums[i-1]){
            int a=max(c1/2,c2/2);
            ans=max(ans,max(min(c1,c2),a));
            c1=c2;
            c2=1;
        }
        else{
            c2++;
        }
        i++;
       }
        int a=max(c1/2,c2/2);
            ans=max(ans,max(min(c1,c2),a));
       return ans;
    }
};