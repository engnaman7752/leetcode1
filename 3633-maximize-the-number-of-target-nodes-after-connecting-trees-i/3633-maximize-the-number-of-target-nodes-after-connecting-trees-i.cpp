class Solution {
    private:
    int bfs(vector<vector<int>>adj,int k,int start)
    {vector<bool>vis(adj.size(),false);
        queue<int>q;
        q.push(start);
        int count=0;
        while(!q.empty()&&k>=0)
        {
            count=q.size()+count;
            int s=q.size();
            for(int j=0;j<s;j++)
            {
                int node=q.front();
                q.pop();
                vis[node]=true;
                for(int i=0;i<adj[node].size();i++ )
                {
                    if(!vis[adj[node][i]])
                    q.push(adj[node][i]);
                }
            }
            k--;
        }
        return count;


    }
    vector<int>dis(vector<vector<int>>adj,int n,int k)
    {vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=bfs(adj,k,i);
        }
        return ans;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<vector<int>>adj1(edges1.size()+1);
        vector<vector<int>>adj2(edges2.size()+1);
        for(int i=0;i<edges1.size();i++)
        {
            int u=edges1[i][0];
            int v=edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
         for(int i=0;i<edges2.size();i++)
        {
            int u=edges2[i][0];
            int v=edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        vector<int>first=dis(adj1,adj1.size(),k);
        vector<int>second=dis(adj2,adj2.size(),k-1);
        int maxx=*max_element(second.begin(),second.end());
        for(int i=0;i<first.size();i++)
        {first[i]+=maxx;

        }
        return first;
        

        
    }
};