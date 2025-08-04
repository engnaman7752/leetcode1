class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
       vector<int>dp(n,-1);
        return solve(0,k,arr,dp);
    }
    int solve(int index,int k,vector<int>&arr,vector<int>&dp){
        int n=arr.size();
        if(index==n)return 0;
        if(dp[index]!=-1)return dp[index];
        int maxx=-1;
        int sum=INT_MIN;
        int ans=INT_MIN;
         for (int i = index; i < min(index + k, n); ++i){
            maxx=max(arr[i],maxx);
            sum=maxx*(i-index+1)+solve(i+1,k,arr,dp);
            ans=max(sum,ans);
        }
         
    return dp[index]=ans;
    }
};