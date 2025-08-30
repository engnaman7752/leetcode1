class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int,int>mp;
        while(n>0){
            mp[n%10]++;
            n/=10;
        }
        int ans=INT_MAX;
        int minn=INT_MAX;
        for(auto [a,b]:mp){
            if(b<minn||(b==minn&&ans>a)){
                ans=a;
                minn=b;
            }
        }
        return ans;
    }
};