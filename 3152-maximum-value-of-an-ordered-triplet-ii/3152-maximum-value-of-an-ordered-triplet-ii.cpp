class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
       long long maxdiff=0;
       long long maxx=nums[0];
       long long ans=0;
       for(int j=1;j<n;j++)
       {
        if(j>=2)
        ans=max(ans,maxdiff*(long long)nums[j]);
        long long diff=maxx-nums[j];
        maxx=max(maxx,(long long)nums[j]);
        maxdiff=max(maxdiff,diff);
       }
        return ans;
    }
};