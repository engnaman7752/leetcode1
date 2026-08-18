class Solution {
public:
    int stoneGameV(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]+=nums[i]+prefix[i-1];
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,n-1,dp,prefix);

    }
    int solve(int i,int j,vector<vector<int>>&dp,vector<int>&prefix){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        for(int k=i;k<j;k++){
            int left=prefix[k]-(i==0?0:prefix[i-1]);
            int right=prefix[j]-prefix[k];
           // cout<<left<<right<<endl;
            if(left>right){
                ans=max(ans,right+solve(k+1,j,dp,prefix));
            }
            else if(left<right){
                ans=max(ans,left+solve(i,k,dp,prefix));
            }
            else{
                ans=max(ans,max((right+solve(k+1,j,dp,prefix)),(left+solve(i,k,dp,prefix))));
            }
        }
        return dp[i][j]=ans;
    }
};