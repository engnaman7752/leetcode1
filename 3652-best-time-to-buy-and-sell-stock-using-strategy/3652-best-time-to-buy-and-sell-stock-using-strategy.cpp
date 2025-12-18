class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long>pre(n);
        vector<long long>sum(n);
        sum[0]=prices[0];
        pre[0]=strategy[0]*prices[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+prices[i]*strategy[i];
            sum[i]=sum[i-1]+prices[i];
        }
        long long ans=pre[n-1];
        for(int i=0;i<n;i++){
            if(i+k-1>=n)break;
            int mid = i + k / 2;
            long long subSum = sum[i + k - 1] - (mid > 0 ? sum[mid - 1] : 0);

            long long tot;
            if (i != 0)
                tot = subSum + (pre[n - 1] - pre[i + k - 1]) + pre[i - 1];
            else
                tot = subSum + (pre[n - 1] - pre[i + k - 1]);

            ans = max(ans, tot);
        }
        return ans;
    }
};