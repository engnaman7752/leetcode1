class Solution {
public:
    int reverseBits(int n) {
        string bits;
        if(n==0)return 0;
        while(n>1){
            if(n%2==0)bits.push_back('0');
            else bits.push_back('1');
            n=n/2;
        }
        bits.push_back('1');
        while(bits.size()!=32)bits.push_back('0');
        int i=1;int ans=0;
        for(int i=31;i>=0;i--){
            if(bits[i]=='1'){
                ans+=(1<<(31-i));
            }
        }
        return ans;
    }
};