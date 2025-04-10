class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         int n=grid.size();
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        if(grid[0][0]!=0)
        return -1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        dis[0][0]=1;
        while(!pq.empty())
        {
            int row=pq.top().first;
            int col=pq.top().second;
            pq.pop();
            for(int i=row-1;i<=row+1;i++ )
            {
                for(int j=col-1;j<=col+1;j++)
                {
                    if(i>=0&&i<n&&j>=0&&j<n)
                    {if(grid[i][j]==0)
                       { if(dis[i][j]>dis[row][col]+1)
                        {
                            dis[i][j]=dis[row][col]+1;
                            pq.push({i,j});
                        }
                        }
                    }
                }
            }
        }
       if(dis[n-1][n-1]==INT_MAX)
       return -1;
       else
       return dis[n-1][n-1]; 
    }
};