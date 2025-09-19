class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<pair<int,int>>>adj(n);
       for(auto f:flights){
        int u=f[0];
        int v=f[1];
        int w=f[2];
        adj[u].push_back({v,w});
       }
        vector<int>dis(n,INT_MAX);
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        dis[src]=0;
        pq.push({0,0,src});
        while(!pq.empty()){
            auto [stay,dist,node]=pq.top();
            pq.pop();
            for(auto [n,w]:adj[node]){
                if(dis[n]>dist+w&&stay<=k){
                    dis[n]=dist+w;
                    pq.push({stay+1,dis[n],n});
                }
            }
        }
        if(dis[dst]==INT_MAX)return -1;
        else return dis[dst];
    }
};