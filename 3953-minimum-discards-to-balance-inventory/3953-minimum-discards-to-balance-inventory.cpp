class Solution {
public:
    int minArrivalsToDiscard(vector<int>& nums, int w, int m) {
        int l=0;
        int r=0;
        int n=nums.size();
        vector<bool>a(n,true);
        unordered_map<int,int>mp;
        int ans=0;
        while(r<n){
            if((r-l+1)>w){
                if(a[l]){
                    mp[nums[l]]--;
                     if (mp[nums[l]] == 0) mp.erase(nums[l]);
                }
                l++;
            }
            
            mp[nums[r]]++;
            if(mp[nums[r]]>m){
                ans++;
                a[r]=false;
                mp[nums[r]]--;
            }
            r++;
        }
        return ans;
    }
};