class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)mp[nums[i]]++;
       if(k==n)return *max_element(nums.begin(),nums.end());
       if(k==1){
         int ans=-1;
        for(auto it:mp){
            if(it.second==1)ans=it.first;
        }
        return ans;
       }
       int ans=-1;
       if(mp[nums[n-1]]==1)ans=nums[n-1];
       if(mp[nums[0]]==1)ans=max(ans,nums[0]);
       return ans;
    }
};