class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        int avg=0;
       sort(nums.begin(),nums.end());
       if(n%2==0)
       avg=(nums[n/2]+nums[(n/2)-1])/2;
       else
       avg=nums[n/2];
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(nums[i]-avg);
        }
        return ans;
    }
};