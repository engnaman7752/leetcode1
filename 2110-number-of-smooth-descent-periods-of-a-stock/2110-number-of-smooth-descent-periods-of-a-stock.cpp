class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long ans=0;
        int i=0;
        while(i<n){
            long long cnt=1;
            while(i<n-1&&prices[i]-prices[i+1]==1){
                cnt++;
                i++;
            }
            ans+=(cnt*(cnt+1))/2;
            i++;
        }
        return ans;
    }
};