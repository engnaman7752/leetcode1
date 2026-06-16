class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                q.push(i);
                vis[i]=0;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto nd:graph[node]){
                        if(vis[nd]==-1){
                            vis[nd]=1-vis[node];
                            q.push(nd);
                        }
                        else{
                            if(vis[node]==vis[nd])return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};