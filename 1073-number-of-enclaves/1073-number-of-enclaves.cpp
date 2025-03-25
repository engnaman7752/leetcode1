class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
         vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int,int>>q;
        int row=0;
        int col=0;
        while(col<grid[0].size())
        {
            if(grid[row][col]==1&&vis[row][col]==false)
            {
                q.push({row,col});
                vis[row][col]=true;
            }
            col++;
        }
        col=col-1;
         while(row<grid.size())
        {
            if(grid[row][col]==1&&vis[row][col]==false)
            {
                q.push({row,col});
                vis[row][col]=true;
            }
            row++;
        }
        col=0;
        row=1;
        while(row<grid.size())
        {
            if(grid[row][col]==1&&vis[row][col]==false)
            {
                q.push({row,col});
                vis[row][col]=true;
            }
            row++;
        }
        row--;
        while(col<grid[0].size())
        {
            if(grid[row][col]==1&&vis[row][col]==false)
            {
                q.push({row,col});
                vis[row][col]=true;
            }
            col++;
        }
        vector<int>decol{-1,0,1,0};
            vector<int>derow{0,-1,0,1};
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int p=0;p<4;p++)
            {
                int ncol=j+decol[p];
                int nrow=i+derow[p];
                if (nrow >= 0 && nrow < vis.size() && ncol >= 0 && ncol < vis[0].size() && grid[nrow][ncol] == 1 && vis[nrow][ncol] == false)
                 {
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=true;
                }
            }

        }
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(vis[i][j]==false&&grid[i][j]==1)
                count++;
            }
        }
return count;



        

    
    }
};