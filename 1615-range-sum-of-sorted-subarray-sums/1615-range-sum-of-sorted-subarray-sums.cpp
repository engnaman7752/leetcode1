class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int sum=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            sum=0;
            for(int j=i;j<n;j++)
            {
                sum=sum+nums[j];
                ans.push_back(sum);

            }
        }
        sort(ans.begin(),ans.end());
        long long int intiger=0;
        for(int i=left-1;i<=right-1;i++)
        intiger=intiger+ans[i];
        return intiger % 1000000007;

    }
};