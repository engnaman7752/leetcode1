class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        map<int,int>mp;
        for(int i=1;i<=1000;i++){
            if(mp.find(i|(i+1))==mp.end())mp[i|(i+1)]=i;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==0)ans.push_back(-1);
            else ans.push_back(mp[nums[i]]);

        }
        return ans;
    }
};