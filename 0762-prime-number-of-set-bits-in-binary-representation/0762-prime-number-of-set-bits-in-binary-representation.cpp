class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<int>prime(32,false);
        prime[1]=true;
        for(int i=2;i<32;i++){
            if(prime[i]==false){
                for(int j=2;j*i<32;j++){
                    prime[j*i]=true;
                }
            }
        }
        int ans=0;
        for(int i=left;i<=right;i++){
            int count=cntBits(i);
            if(prime[count]==false)ans++;
        }
        return ans;
    }
    int cntBits(int i){
        int cnt=0;
        while(i>0){
            if((1&i)>0){
                cnt++;
            }
           i=i>>1;
        }
        return cnt;
    }
};