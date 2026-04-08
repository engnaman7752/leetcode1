class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int MOD=1e9+7;
        for(auto q:queries){
            int l=q[0];
            int r=q[1];
            int k=q[2];
            long long v=q[3];
            while(l<=r){
                long long a=(nums[l]*v);
                nums[l]=a%MOD;
                l+=k;
            }

        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        ans^=nums[i];
        return ans;

        
    }
};