class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        long long left=0;
        long long right=0;
        unordered_map<long long,long long>mp;
        long long n=nums.size();
        int sum=0;
        long long ans=n+1;
        while(right<n){
            mp[nums[right]]++;
            if(mp[nums[right]]==1)sum+=nums[right];
            while(sum>=(1LL*k)){
                ans=min(ans,right-left+1);
                mp[nums[left]]--;
                if(mp[nums[left]]==0)sum-=nums[left];
                left++;
            }
            right++;
        }
        if(ans==n+1)return -1;
        else return ans;
    }
};