class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long n = nums.size();
        map<int,int> mp;
     
        long long sum  = accumulate(nums.begin(),nums.end(),0ll);
        int r = sum%p;
        if(sum%p==0) return 0;
        int res = n;
        int s = 0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            s+=nums[i]%p;
            s%=p;

            if(mp.count((s+(p-r))%p)){
                res = min(res,i-mp[(s+(p-r))%p]);
            }
            mp[s]=i;
        }
        return res < n ? res : -1;
    }
};