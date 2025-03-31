class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>>adj(graph.size());//reverse all the edges
        vector<int>indegree(adj.size(),false);
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[graph[i][j]].push_back(i);
            }
        }
        for(int i=0;i<adj.size();i++)
        {for(int j=0;j<adj[i].size();j++)
           indegree[adj[i][j]]++;
        }
        vector<int>ans;
        queue<int>q;
       for(int i=0;i<indegree.size();i++)
       {
           if(indegree[i]==0)
           q.push(i);
       }
       while(!q.empty())
       {
           int node=q.front();
           ans.push_back(node);
           q.pop();
           for(auto it:adj[node])
           {
               indegree[it]--;
               if(indegree[it]==0)
               q.push(it);
           }
       }
       sort(ans.begin(),ans.end());
        return ans;
    }
};