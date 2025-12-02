class Solution {
    long long MOD=1e9+7;
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<long long,long long>mp;
        for(auto p:points){
            mp[p[1]]++;
        }
        if(mp.size()==1)return 0;
        long long ans=0;
        long long sum=0;
        for(auto [a,b]:mp){
            long long edge=(b)*(b-1)/2;
            ans+=sum*edge;
            sum+=edge;
        }
return ans%(MOD);
    }
};