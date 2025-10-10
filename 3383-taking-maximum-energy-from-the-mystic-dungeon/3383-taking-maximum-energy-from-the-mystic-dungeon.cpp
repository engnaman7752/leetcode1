class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int>dp(n);
        for(int i=0;i<k;i++)dp[i]=energy[i];
        for(int i=k;i<n;i++){
            int a=energy[i]+dp[i-k];
            int b=energy[i];
            dp[i]=max(a,b);
        }
        int ans=INT_MIN;
        for(int i=n-1;i>=n-k;i--){ans=max(ans,dp[i]);}
        return ans;
    }
};