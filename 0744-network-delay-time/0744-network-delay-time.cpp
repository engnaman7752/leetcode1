class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto t:times){
            int u=t[0];
            int v=t[1];
            int w=t[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>time(n+1,INT_MAX);
        time[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [delay,node]=pq.top();
            pq.pop();
            for(auto [nd,w]:adj[node]){
                if(delay!=INT_MAX && time[nd]>(delay+w)){
                    time[nd]=delay+w;
                    pq.push({delay+w,nd});
                }
            }
        }
        int maxTime=*max_element(time.begin()+1,time.end());
        if(maxTime==INT_MAX)return -1;
        else return maxTime;
    }
};