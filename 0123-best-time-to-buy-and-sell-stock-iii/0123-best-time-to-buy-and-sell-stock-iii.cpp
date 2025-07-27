class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,INT_MIN)));
        return solve(0,0,2,prices,dp);
        
    }
    int solve(int index,int count,int left,vector<int>& nums,vector<vector<vector<int>>>&dp){
        int n=nums.size();
        if(index==n)return 0;
        if(left==0)return 0;
        if(dp[index][count][left]!=INT_MIN)return dp[index][count][left];
        int skip=solve(index+1,count,left,nums,dp);
        if(count==0){
            int buy=-nums[index]+solve(index+1,count+1,left,nums,dp);
            return dp[index][count][left]=max(skip,buy);
        }
        else{
             int sell=nums[index]+solve(index+1,count-1,left-1,nums,dp);
            return dp[index][count][left]=max(skip,sell);
        }
        
    }
};