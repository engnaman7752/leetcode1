class Solution {
public:
    int n;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        vector<tuple<int,int,int>>time;
        for(int i=0;i<n;i++){
            time.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(time.begin(),time.end());
        for(int i=0;i<n;i++){
            auto[s,e,p]=time[i];
            startTime[i]=s;
            endTime[i]=e;
            profit[i]=p;
        }

        vector<int>dp(n,-1);
        return solve(0,startTime,endTime,profit,dp);

    }
    int solve(int i,vector<int>& startTime, vector<int>& endTime, vector<int>& profit,vector<int>&dp){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int t=lower_bound(startTime.begin(),startTime.end(),endTime[i])-startTime.begin();
        int take=profit[i]+solve(t,startTime,endTime,profit,dp);
        int notTake=solve(i+1,startTime,endTime,profit,dp);
        return dp[i]=max(take,notTake);
    }
};