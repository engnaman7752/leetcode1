class Solution {
public:
    long long countCommas(long long n) {
        if(n<=999)return 0;
        long long num=999;
        long long ans=0;
        int cnt=1;
        while(true){
            //cout<<num<<endl;
            if(n>(num*1000+999)){
                ans+=cnt*(((num*1000)+999)-num);
                num=(num*1000)+999;
            }
            else{
                ans+=cnt*(n-num);
                return ans;
            }
            cnt++;
        }
        return 0;
    }
};