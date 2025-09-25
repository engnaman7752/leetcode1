class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n);
        for(int i=0;i<n;i++)
        {
           { for(int j=0;j<triangle[i].size();j++)
            if(i<n-1)
            dp[i].push_back(0);
            else if(i==n-1)
            dp[i].push_back(triangle[i][j]);}
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    
      
    } 
   
};