class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int ans=0;
        int n=fruits.size();
        for(int i=0;i<fruits.size();i++){
           
            ans+=fruits[i][i];
            fruits[i][i]=0;}
            vector<vector<int>>dp1(n,vector<int>(n,-1));
             vector<vector<int>>dp2(n,vector<int>(n,-1));
            ans+=solve1(0,n-1,n-1,fruits,dp1);
            
            ans+=solve2(n-1,0,n-1,fruits,dp2);
           
            return ans;
    }
    int solve1(int row,int col,int rem,vector<vector<int>>& fruits,vector<vector<int>>&dp){
        int n=fruits.size();
        if(row==n-1&&col==n-1)return 0;
       if(row>=n||col>=n||row<0||col<0)return INT_MIN;
        if(rem<0)return INT_MIN;
        if(dp[row][col]!=-1)return dp[row][col];
        int left=solve1(row+1,col-1,rem-1,fruits,dp);
        int same=solve1(row+1,col,rem-1,fruits,dp);
        int right=solve1(row+1,col+1,rem-1,fruits,dp);
        return dp[row][col]=fruits[row][col]+max(left,max(right,same));
    }
      int solve2(int row,int col,int rem,vector<vector<int>>& fruits,vector<vector<int>>&dp){
        int n=fruits.size();
        if(row==n-1&&col==n-1)return 0;
        if(row>=n||col>=n||row<0||col<0)return INT_MIN;
        if(rem<0)return INT_MIN;
        if(dp[row][col]!=-1)return dp[row][col];
        int left=solve2(row-1,col+1,rem-1,fruits,dp);
        int same=solve2(row,col+1,rem-1,fruits,dp);
        int right=solve2(row+1,col+1,rem-1,fruits,dp);
        return dp[row][col]=fruits[row][col]+max(left,max(right,same));
    }

};