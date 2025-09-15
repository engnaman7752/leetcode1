class Solution {
public:
    double myPow(double x, int a) {
        long long n=a;
        if(n==0)return 1;
        if(n<0){
            x=1/x;
            n=-n;
        }
        if(n==1)return x;
        if(n==2)return x*x;
        if(n%2==0)return myPow(x*x,n/2);
        else return x*myPow(x*x,n/2);
    }
};