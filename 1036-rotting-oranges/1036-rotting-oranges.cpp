class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {q.push({i,j});
                vis[i][j]=true;}
            }
        }
        int ans=0;
        int x=1;
        int rotton=2;
        while(!q.empty())
    {bool flag=false;
    int s=q.size();
        for(int i=0;i<s;i++)
    {int row=q.front().first;
     int col=q.front().second;
    q.pop();
    if(row+1<vis.size()&&vis[row+1][col]==false&&grid[row+1][col]==x)
    {
        vis[row+1][col]=true;
        grid[row+1][col]=rotton;
        q.push({row+1,col});
        flag=true;

    }
    if(row-1>=0&&vis[row-1][col]==false&&grid[row-1][col]==x)
    {
        vis[row-1][col]=true;
        grid[row-1][col]=rotton;
        q.push({row-1,col});
        flag=true;
        
    }
    if(col+1<vis[0].size()&&vis[row][col+1]==false&&grid[row][col+1]==x)
    {
        vis[row][col+1]=true;
        grid[row][col+1]=rotton;
        q.push({row,col+1});
        flag=true;

    }
    if(col-1>=0&&vis[row][col-1]==false&&grid[row][col-1]==x)
    {
        vis[row][col-1]=true;
        grid[row][col-1]=rotton;
        q.push({row,col-1});
        flag=true;
        
    }
    }
if(flag)
ans++;

    }
     for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {return -1;}
            }
        }
return ans;
        
    }
};