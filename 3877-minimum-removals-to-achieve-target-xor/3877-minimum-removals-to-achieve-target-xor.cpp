class Solution {
public:
    int n;
    int minRemovals(vector<int>& nums, int target) {
        int xorr=0;
         n=nums.size();
        for(int i=0;i<n;i++)xorr^=nums[i];
        map<pair<int,int>,int>dp;
        if(xorr==target)return 0;
       int ans=solve(0,xorr,target,dp,nums);
        if(ans==INT_MAX)return -1;
        return ans;
    }
    long long solve(int i,int xorr,int target,map<pair<int,int>,int>&dp,vector<int>&nums){
        if(target==xorr)return 0;
        
        if(i==n){return INT_MAX;
        }
        if(dp.find({i,xorr})!=dp.end())return dp[{i,xorr}];
        return dp[{i,xorr}]=min(solve(i+1,xorr,target,dp,nums),1+solve(i+1,xorr^nums[i],target,dp,nums));
    }
};