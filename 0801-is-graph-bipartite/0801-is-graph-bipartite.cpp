class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>vis(graph.size(),-1);
        queue<int>q;
      for(int j=0;j<vis.size();j++)
        {if(vis[j]==-1)
            {q.push(j);
        vis[j]=0;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(int i=0;i<graph[x].size();i++)
            {
                if(vis[graph[x][i]]==-1)
                {q.push(graph[x][i]);
                vis[graph[x][i]]=1-vis[x];}
                else
                {
                    if(vis[graph[x][i]]==vis[x])
                    return false;
                }
            }
        }}}
        return true;
    }
};