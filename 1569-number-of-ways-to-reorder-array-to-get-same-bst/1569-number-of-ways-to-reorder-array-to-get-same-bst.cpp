class Solution {
public:
vector<vector<int>>pascal;

int mod=1e9+7;
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        pascal.assign(n+1,vector<int>(n+1,1));
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
               pascal[i][j] = (pascal[i-1][j-1] + pascal[i-1][j]) % mod;
            }
        }
        return ((solve(nums)%mod)-1)%mod;
    }
    int solve(vector<int>nums){
        int n=nums.size();
        if(n<3)return 1;
        int root=nums[0];
        vector<int>left;
        vector<int>right;
        for(int i=1;i<n;i++){
            if(nums[i]<root)left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        int x=solve(left)%mod;
        int y=solve(right)%mod;
        return (1LL * x * y % mod) * pascal[n-1][left.size()] % mod;
    }
};