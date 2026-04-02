class Solution {
public:
int n;
int m;
vector<vector<vector<int>>>dp;
vector<vector<int>>nums;
    int maximumAmount(vector<vector<int>>& coins) {
        n=coins.size();
        m=coins[0].size();
        nums=coins;
        dp.assign(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        return solve(0,0,2);
    }
    int solve(int i,int j,int k){
        if(i>=n || j>=m)return INT_MIN;
        if(i==n-1&&j==m-1){
            if(nums[i][j]<0 && k>0) return 0;
            return nums[i][j];
        }
        if(dp[i][j][k]!=INT_MIN)return dp[i][j][k];
        if(nums[i][j]>=0){
            return dp[i][j][k]=nums[i][j]+max(solve(i+1,j,k),solve(i,j+1,k));
        }
        else{
            int t=INT_MIN;
            if(k>0)
             t=max(solve(i+1,j,k-1),solve(i,j+1,k-1));
            int nt=nums[i][j]+max(solve(i+1,j,k),solve(i,j+1,k));
            return dp[i][j][k]= max(t,nt);
        }
    }
};