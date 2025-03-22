class Solution {
    private:
    void bfs(int i,int j,vector<vector<int>>& image,vector<vector<bool>>&vis,int color)
{
    queue<pair<int,int>>q;
    pair<int,int>p{i,j};
    vis[i][j]=true;
    int x=image[i][j];
    image[i][j]=color;
    q.push(p);
    while(!q.empty())
    {int row=q.front().first;
     int col=q.front().second;
    q.pop();
    if(row+1<vis.size()&&vis[row+1][col]==false&&image[row+1][col]==x)
    {
        vis[row+1][col]=true;
        image[row+1][col]=color;
        q.push({row+1,col});

    }
    if(row-1>=0&&vis[row-1][col]==false&&image[row-1][col]==x)
    {
        vis[row-1][col]=true;
        image[row-1][col]=color;
        q.push({row-1,col});
        
    }
    if(col+1<vis[0].size()&&vis[row][col+1]==false&&image[row][col+1]==x)
    {
        vis[row][col+1]=true;
        image[row][col+1]=color;
        q.push({row,col+1});

    }
    if(col-1>=0&&vis[row][col-1]==false&&image[row][col-1]==x)
    {
        vis[row][col-1]=true;
        image[row][col-1]=color;
        q.push({row,col-1});
        
    }


    }
}
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    vector<vector<bool>> vis(image.size(), vector<bool>(image[0].size(), false));
    bfs(sr,sc,image,vis,color);
    return image;
        
    }
};