class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long ans=0;
        if(n>k)
        ans=(long)(n-k)*k+ans;
        if(m>k)
        ans=(long)(m-k)*k+ans;
        return ans;
        
    }
};