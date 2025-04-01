class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
         if (n == 1) return {0};
         vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
           adj[edges[i][1]].push_back(edges[i][0]) ;
           adj[edges[i][0]].push_back(edges[i][1]) ;
        }
        vector<int>indegree(adj.size(),0);
        
        for(int i=0;i<adj.size();i++)
        {for(int j=0;j<adj[i].size();j++)
           indegree[adj[i][j]]++;
        }
        vector<int>ans;
        queue<int>q;
       for(int i=0;i<indegree.size();i++)
       {
           if(indegree[i]==1)
           q.push(i);
           
       }
       while (!q.empty()) {
            int size = q.size();
            ans.clear();

            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                ans.push_back(node);

                for (int j = 0; j < adj[node].size(); j++) {
                    int neighbor = adj[node][j];
                    indegree[neighbor]--;

                    if (indegree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }
        return ans;
        
    }
};