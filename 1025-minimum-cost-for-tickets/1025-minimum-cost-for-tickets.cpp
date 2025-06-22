class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
        int n=days.size();
         solve(0,days,costs,dp);
        return dp[0];   
    }
    int solve(int i,vector<int>& days, vector<int>& costs,vector<int>& dp)
    {int n=days.size();
        if(n<=i)return 0;
        if(dp[i]!=-1)return dp[i];
        int one=costs[0]+solve(i+1,days,costs,dp);
        int j=i;
        while(j<n&&days[j]-days[i]<7)j++;
        int seven=costs[1]+solve(j,days,costs,dp);
         j=i;
        while(j<n&&days[j]-days[i]<30)j++;
        int thirty=costs[2]+solve(j,days,costs,dp);
        cout<<one<<endl;
        return dp[i]=min(one,min(seven,thirty));

    }
};