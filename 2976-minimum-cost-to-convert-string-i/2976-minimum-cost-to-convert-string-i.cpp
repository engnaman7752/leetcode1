class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>adj(26,vector<long long>(26,LLONG_MAX));
        for(long long i=0;i<original.size();i++){
            adj[original[i]-'a'][changed[i]-'a']=min(1LL*cost[i],adj[original[i]-'a'][changed[i]-'a']);
        }
        for(long long vis=0;vis<26;vis++){
            for(long long i=0;i<26;i++){
                for(long long j=0;j<26;j++){
                    if(adj[i][vis]!=LLONG_MAX && adj[vis][j]!= LLONG_MAX)
                    adj[i][j]=min(adj[i][j],adj[i][vis]+adj[vis][j]);
                }
            }
        }
        long long ans=0;
        for(long long p=0;p<s.size();p++){
            long long i=s[p]-'a';
            long long j=t[p]-'a';
            if(i==j)continue;
            if(adj[i][j]==LLONG_MAX)return -1;
            else 
            ans+=adj[i][j];
        }
        return ans;
    }
};