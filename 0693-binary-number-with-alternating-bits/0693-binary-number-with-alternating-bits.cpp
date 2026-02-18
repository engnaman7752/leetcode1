class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n==1)return true;
        while(n>0){
            int k=n>>1;
            if((k^n)%2==0)return false;
            n=k;
        }
        return true;
    }
};