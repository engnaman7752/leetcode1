class Solution {
public:
 int n;
 int k;
    vector<long long> resultArray(vector<int>& nums, int _k) {
        k=_k;
        n=nums.size();
        vector<long long>ans(k);
        for(int i=0;i<k;i++){
            vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(k+1,vector<long long>(3,-1)));
            ans[i]=(solve(0,1,0,i,nums,dp));
        }
        return ans;
    }
    long long solve(long long i,long long mod,long long step,int x,vector<int>& nums,vector<vector<vector<long long>>>&dp){
        if(i==n){
            if((step==1 || step==2) && mod==x)return 1;
            return 0;
        }
        if(dp[i][mod][step]!=-1)return dp[i][mod][step];
        long long ans=0;
        if(step==0){
            ans+=solve(i+1,mod,step,x,nums,dp);
            ans+=solve(i+1,(mod*nums[i])%k,step+1,x,nums,dp);
        }
        if(step==1){
            ans+=solve(i+1,mod,step+1,x,nums,dp);
            ans+=solve(i+1,(mod*nums[i])%k,step,x,nums,dp);
        }
        if(step==2){
            ans+=solve(i+1,mod,step,x,nums,dp);
        }
        return dp[i][mod][step]=ans;
    }
};