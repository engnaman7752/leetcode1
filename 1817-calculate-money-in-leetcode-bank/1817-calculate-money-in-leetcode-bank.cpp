class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int mon=1;
        int day=0;
        for(int i=1;i<=n;i++){
            ans+=mon+day;
            day++;
            if(day==7){
                day=0;
                mon++;
            }
            
        }
        return ans;
    }
};