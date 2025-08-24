class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0)return false;
        map<int,int>mp;
        for(int i=0;i<n;i++)mp[nums[i]]++;
        for(auto [a,freq]:mp){
            if(freq>n/k)return false;
        }
        return true;
        
    }
};