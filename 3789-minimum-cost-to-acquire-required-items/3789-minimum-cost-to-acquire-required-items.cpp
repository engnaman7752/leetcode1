class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = LLONG_MAX;
        // for(int i = 0; i <= max(need1, need2); i++){
        //     ans = min(ans,
        //         1LL * costBoth * i +
        //         1LL * cost1 * max(need1 - i, 0) +
        //         1LL * cost2 * max(need2 - i, 0)
        //     );
        // }
        // int start=0; end=max(need1,need2);
        // while(start<=end){
        //     long long i=start+(end-start)/2;
        //     long long pre=ans;
        //      ans = min(ans,
        //         1LL * costBoth * i +
        //         1LL * cost1 * max(need1 - i, 0) +
        //         1LL * cost2 * max(need2 - i, 0)
        //     );
        //     if(pre==ans)end=mid-1;
        //     else start=mid+1;
        // }
        // return ans;
        
        
        if (1LL * costBoth >= 1LL * cost1 + 1LL * cost2) {
            return 1LL * cost1 * need1 + 1LL * cost2 * need2;
        }
        long long k = min(1LL * need1, 1LL * need2);
        long long res = 1LL * costBoth * k;
        need1 -= (int)k;
        need2 -= (int)k;
       
        res += 1LL * min((long long)cost1, (long long)costBoth) * need1;
        res += 1LL * min((long long)cost2, (long long)costBoth) * need2;
        return res;
   

    }   
};
