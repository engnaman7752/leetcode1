class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj(n+1);
        for(auto e:roads){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=INT_MAX;
        vector<bool>vis(n+1,false);
        queue<int>q;
        q.push(1);
        vis[1]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto nd:adj[node]){
                if(!vis[nd]){
                    q.push(nd);
                    vis[nd]=true;
                }
            }

        }
        for(auto e:roads){
            if(vis[e[0]]){
                ans=min(ans,e[2]);
            }
        }
        return ans;
    }
};