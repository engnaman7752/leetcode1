class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<=n-k;i++)
        {map<int,int>m;
            for(int j=0;j<k;j++)
            {m[nums[i+j]]++;
            if(m[nums[i+j]]==1)
                mp[nums[i+j]]++;
            }

        }
        int ans=-1;
        for(auto it:mp)
        {
            if(it.second==1&&it.first>ans)
            ans=it.first;
        }
        return ans;

        
    }
};