class Solution {
    private:
    int modPow(long long base, long long exp, int mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        vector<vector<int>>adj(edges.size()+2);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       vector<bool>vis(adj.size(),false);
       vis[0]=true;
       queue<int>q;
       q.push(1);
       int count=0;
       while(!q.empty())
       {int s=q.size();
       for(int k=0;k<s;k++)
        {int node=q.front();
        q.pop();
        vis[node]=true;
        for(int i=0;i<adj[node].size();i++)
        {
            if(!vis[adj[node][i]])
            q.push(adj[node][i]);
        }
        }
        count++;
       }
      return modPow(2,count-2,1e9 + 7);
        
    }
};