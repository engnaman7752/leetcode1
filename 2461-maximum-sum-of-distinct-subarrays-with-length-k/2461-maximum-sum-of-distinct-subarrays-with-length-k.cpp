class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int left=0;
        int right=0;
        int n=nums.size();
        long long ans=0;
        vector<long long>pre(n,0);pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]+=pre[i-1]+nums[i];
        }
        while(right<n){
            if(mp.find(nums[right])!=mp.end()){
                if(left<=mp[nums[right]])
                left=mp[nums[right]]+1;
            }
            mp[nums[right]]=right;
            if(right-left+1==k){
                
                long long sum=0;
                if(left==0)sum=pre[right];
                else sum=pre[right]-pre[left-1];
               ans=max(ans,sum);
               mp.erase(nums[left]);
               left++;
            }
            right++;
        }
        return ans;
    }
};