class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        mp[nums[i]]++;
        sort(nums.begin(),nums.end(),[&](auto a,auto b)
        {
            if(mp[a]==mp[b])
            return a>b;
            return mp[a]<mp[b];
        });
        return nums;
    }
};