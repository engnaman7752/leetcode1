class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<vector<int>>dp(events.size(),vector<int>(k+1,-1));
        return solve(0,events,k,dp);
        
    }
    int solve(int index,vector<vector<int>>& events, int k,vector<vector<int>>& dp)
    {int n=events.size();
        if(k==0)return 0;
        if(index==n)return 0;
        if(dp[index][k]!=-1)return dp[index][k];
        int take=0;
        int next=binarySearch(events,events[index][1]);
        cout<<next<<endl;
        take=events[index][2]+solve(next,events,k-1,dp);
        int notTake=solve(index+1,events,k,dp);
        return dp[index][k]=max(take,notTake);
    }
    int binarySearch(vector<vector<int>>& events, int target)
    {
        int left=0;
        int right=events.size();
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(events[mid][0]<=target)
            left=mid+1;
            else
            right=mid;
        }
        return left;
    }
};