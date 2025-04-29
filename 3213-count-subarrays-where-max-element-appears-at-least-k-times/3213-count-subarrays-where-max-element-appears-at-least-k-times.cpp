class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=0;
        int maxx=*max_element(nums.begin(),nums.end());
        int cnt=0;
        int intial=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==maxx)
            cnt++;
           while(cnt==k)
           {if(nums[intial]==maxx)
           cnt--;
           intial++;

           }
           ans=ans+intial;
        }
        return ans;
    }
};