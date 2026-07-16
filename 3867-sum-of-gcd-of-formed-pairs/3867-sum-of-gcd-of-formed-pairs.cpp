class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        vector<int>gc(n);
        int maxx=nums[0];
        for(int i=0;i<n;i++){
            maxx=max(nums[i],maxx);
            gc[i]=gcd(nums[i],maxx);
        }
        sort(gc.begin(),gc.end());
        int low=0;int high=n-1;
        while(low<high){
            ans+=gcd(gc[low],gc[high]);
            low++;
            high--;
        }
        return ans;
    }
};