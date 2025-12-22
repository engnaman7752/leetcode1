class Solution {
public:
    int mirrorDistance(int n) {
        long long k=0;
        int p=n;
        while(n>0){
            k*=10;
            k+=n%10;
            n/=10;
        }
        return abs(p-k);
    }
};