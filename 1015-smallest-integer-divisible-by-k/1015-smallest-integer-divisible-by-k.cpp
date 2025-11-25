class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0)return -1;
        long long rem=0;
        int count=1;
        int len=100;
        while(count<=k){
            rem=((rem*10)+1)%k;
            if(rem==0)return count;
            count++;
        }
        return -1;
    }
};