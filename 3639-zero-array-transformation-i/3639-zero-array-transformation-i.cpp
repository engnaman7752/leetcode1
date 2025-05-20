class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>diff(n+1,0);
        //diff[0]=nums[0];
        for(int i=1;i<n+1;i++)
        {
            diff[i]=diff[i]-diff[i-1];
        }
        for(int i=0;i<queries.size();i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            diff[l]=diff[l]+1;
            diff[r+1]=diff[r+1]-1;

        }
        for(int i=1;i<n+1;i++)
        {
            diff[i]=diff[i]+diff[i-1];
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>diff[i])
            return false;
        }
        return true;
        
    }
};