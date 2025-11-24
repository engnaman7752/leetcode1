class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long num=0;
        int n=nums.size();
        vector<bool>ans(n,false);
        for(int i=0;i<n;i++){
           num=((num<<1)+nums[i])%5;
            if(num==0)ans[i]=true;
        }
        return ans;
    }
};