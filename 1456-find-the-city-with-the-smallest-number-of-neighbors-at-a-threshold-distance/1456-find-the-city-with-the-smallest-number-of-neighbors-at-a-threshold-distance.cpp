class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj_mat(n,vector<int>(n,INT_MAX));
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj_mat[u][v]=w;
            adj_mat[v][u]=w;
        }
        for(int vis=0;vis<n;vis++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {if(adj_mat[i][vis]!=INT_MAX&&adj_mat[vis][j]!=INT_MAX)
                    adj_mat[i][j]=min(adj_mat[i][j],adj_mat[i][vis]+adj_mat[vis][j]);
                }
            }
        }
        pair<int,int>ans={INT_MAX,0};
        for(int i=0;i<n;i++)
        {int count=0;
            for(int j=0;j<n;j++)
            {if(adj_mat[i][j]<=distanceThreshold&&i!=j)
            count++;
            }
            if(ans.first>=count)
            ans={count,i};
        }
        return ans.second;
    }
};