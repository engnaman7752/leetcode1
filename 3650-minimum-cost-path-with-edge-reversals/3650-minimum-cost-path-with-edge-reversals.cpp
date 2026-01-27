class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }
        vector<int>dis(n,INT_MAX);
        dis[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [newdis,node]=pq.top();
            pq.pop();
            for(auto it:adj[node])
            {int x=it.first;
                if((newdis+it.second)<dis[x])
                {
                    dis[it.first]=newdis+it.second;
                    pq.push({newdis+it.second,it.first});
                }
            }
        }
        if(dis[n-1]!=INT_MAX)return dis[n-1];
        else return -1;        
    }
};