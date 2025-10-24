class Solution {
public:
    int nextBeautifulNumber(int n) {
        for(int i=n+1;i<=1e8;i++){
            map<int,int>mp;
            int num=i;
            while(num>0){
                mp[num%10]++;
                num=num/10;
            }
            bool flag=true;
            for(auto it:mp){
                if(it.second!=it.first){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return i;
            }
        }
        return 0;
    }
};