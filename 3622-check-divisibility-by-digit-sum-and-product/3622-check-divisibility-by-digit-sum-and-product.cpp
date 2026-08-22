class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0;
        long long multi=1;
        long long x=n;
        while(n>0){
            long long dig=n%10;
            sum=sum+dig;
            multi=multi*dig;
            n=n/10;

        }
    
        if(x%(sum+multi)==0)return true;
        else return false;
        
    }
};