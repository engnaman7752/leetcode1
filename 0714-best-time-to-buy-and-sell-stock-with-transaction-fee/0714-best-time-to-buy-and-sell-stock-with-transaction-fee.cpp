class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,INT_MIN));
        return solve(0,false,prices,dp,fee);
    }
     int solve(int index,bool check,vector<int>&nums,vector<vector<int>>& dp,int fee){
        int n=nums.size();
        if(index==n)return 0;
        if(dp[index][check]!=INT_MIN)return dp[index][check];
        int skip=solve(index+1,check,nums,dp,fee);
        if(check)
        {
            return dp[index][check]=max((nums[index]+solve(index+1,!(check),nums,dp,fee)),skip);

        }
        else {
            return dp[index][check]=max((-fee-nums[index]+solve(index+1,!(check),nums,dp,fee)),skip);
        }

    }
};