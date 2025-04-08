class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i+1);
        }
        int ans=0;
        for(auto it:mp)
        {
            if(it.second.size()>1)
            {
            int x=((it.second[it.second.size()-2])/3);
            if((it.second[it.second.size()-2])%3!=0)
                 x++;
            ans=max(ans,x);}
        }
        return ans;
    }
};