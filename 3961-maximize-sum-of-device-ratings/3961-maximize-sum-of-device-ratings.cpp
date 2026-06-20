class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        long long n=units.size();
        long long ans=0;
        if(units[0].size()==1){
            for(int i=0;i<n;i++)ans+=units[i][0];
            return ans;
        }
        vector<long long>minimum(n);
        vector<long long>second_minimum(n);
        for(long long i=0;i<n;i++){
            long long a=1e15;
            long long b=1e15;
            for(long long j=0;j<units[i].size();j++){
                if(a>=units[i][j]){
                    b=a;
                    a=units[i][j];
                }
                else if(b>units[i][j]){
                    b=units[i][j];
                }
            }
            minimum[i]=a;
            second_minimum[i]=b;
        }
        ans=accumulate(second_minimum.begin(),second_minimum.end(),0LL);
        ans-=*min_element(second_minimum.begin(),second_minimum.end());
        ans+=*min_element(minimum.begin(),minimum.end());
        return ans;
    }
};