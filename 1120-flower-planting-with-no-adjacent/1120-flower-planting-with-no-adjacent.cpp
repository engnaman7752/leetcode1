class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
         vector<vector<int>>adj(n);
        for(int i=0;i<paths.size();i++)
        {
            int u=paths[i][0]-1;
            int k=paths[i][1]-1;
            adj[u].push_back(k);
            adj[k].push_back(u);
        }
        vector<int>v(n,0);;
        solve(0,adj,4,v);
        return v;
    }
    bool solve(int k,vector<vector<int>>& adj,int m,vector<int>&v)
    {
        if(k==adj.size())
        return true;
        int node=k;
        for(int i=1;i<=m;i++)
        {
            if(check(i,node,adj,v))
            {
                v[node]=i;
            
            if(solve(k+1,adj,m,v))
            return true;
            else
            v[node]=0;
        }
        }
       return false;
        
    }
    bool check(int no,int node,vector<vector<int>>& adj,vector<int>&v)
    {
        for(int i=0;i<adj[node].size();i++)
        {
            if(v[adj[node][i]]==no) return false;
        }
        return true;
    }
};