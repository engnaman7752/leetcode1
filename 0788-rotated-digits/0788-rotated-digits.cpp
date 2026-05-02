class Solution {
public:
    int rotatedDigits(int n) {
        vector<int>v{0,1,5,-1,-1,2,9,-1,8,6};
        int ans=0;
        for(int i=0;i<=n;i++){
            bool flag=false;
            int num=i;
            while(num>0){
                if(v[num%10]==-1){
                    flag=false;
                    break;
                }
                if(v[num%10]!=(num%10))flag=true;
                num=num/10;
            }
            if(flag)ans++;
        }
        return ans;
        
    }
};