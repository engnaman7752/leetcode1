class Solution {
public:
void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>&vis)
{
    queue<pair<int,int>>q;
    pair<int,int>p{i,j};
    vis[i][j]=true;
    q.push(p);
    while(!q.empty())
    {int row=q.front().first;
     int col=q.front().second;
    q.pop();
    if(row+1<vis.size()&&vis[row+1][col]==false&&grid[row+1][col]=='1')
    {
        vis[row+1][col]=true;
        q.push({row+1,col});

    }
    if(row-1>=0&&vis[row-1][col]==false&&grid[row-1][col]=='1')
    {
        vis[row-1][col]=true;
        q.push({row-1,col});
        
    }
    if(col+1<vis[0].size()&&vis[row][col+1]==false&&grid[row][col+1]=='1')
    {
        vis[row][col+1]=true;
        q.push({row,col+1});

    }
    if(col-1>=0&&vis[row][col-1]==false&&grid[row][col-1]=='1')
    {
        vis[row][col-1]=true;
        q.push({row,col-1});
        
    }


    }
}
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    if(vis[i][j]==false)
                    {ans++;
                        bfs(i,j,grid,vis);
                    }               
                 }
            }
        }
        return ans;
        
    }
};