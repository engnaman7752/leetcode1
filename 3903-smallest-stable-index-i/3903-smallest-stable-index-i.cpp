class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>minn(n);
        vector<int>maxx(n);
        int a=nums[0];
        for(int i=0;i<n;i++){
            a=max(a,nums[i]);
            maxx[i]=a;
        }
        a=nums[n-1];
        for(int i=n-1;i>=0;i--){
            a=min(a,nums[i]);
            minn[i]=a;
        }
        for(int i=0;i<n;i++){
            if(maxx[i]-minn[i]<=k)return i;
        }
        return -1;
    }
};