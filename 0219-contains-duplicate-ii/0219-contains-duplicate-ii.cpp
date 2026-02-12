class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        int right=0;
        map<int,int>mp;
        while(right<n){
            if(mp.find(nums[right])!=mp.end())return true;
            mp[nums[right]]=right;
            if(right-left+1>k){mp.erase(nums[left]);left++;}
            right++;
        }
        return false;
    }
};