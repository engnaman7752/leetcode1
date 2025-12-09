class Solution {
    long long MOD=1e9+7;
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>cnt;
        long long ans=0;
        unordered_map<int,int>curr;
        int n=nums.size();
        for(int i=0;i<n;i++){
            cnt[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=0&&cnt[2*nums[i]]-curr[2*nums[i]]>=0&&curr[2*nums[i]]>0){
                ans+=((cnt[2*nums[i]]-curr[2*nums[i]])%MOD*curr[2*nums[i]]%MOD)%MOD;
            }
            if(nums[i]==0){
               ans+=((cnt[2*nums[i]]-curr[2*nums[i]]-1)%MOD*curr[2*nums[i]]%MOD)%MOD;     
                }
            curr[nums[i]]++;
        }
        return ans%MOD;
    }
};