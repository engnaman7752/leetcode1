class Solution {
public:
    int binaryGap(int n) {
        int pre=-1;
        int last=-1;int cnt=1;int ans=0;
        while(n>0){
            if((n&1)>0){
                if(pre==-1){
                    pre=cnt;
                }
                if(last==-1){
                    last=cnt;
                    ans=max(ans,last-pre);
                }
                else{
                    pre=last;
                    last=cnt;
                    ans=max(ans,last-pre);
                }
            }
            cnt++;
            n=n>>1;
        }
        return ans;
    }
};